// bee 1726 - Amigos
// Alonso Martins
// 04/01/2025
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// #define DEBUG

typedef struct Node
{
    bool is_binary_operator;
    int value;
    struct Node *left_operand;
    struct Node *right_operand;
} Node;


Node mem_pool[85];
int count_mem_pool = 0;
char valid_operators[]  = "*+-";
char precedende_order[] = "122";

int precedence(char);
int apply_operation(Node *);
bool is_operator(char);
void print_bits(int);
void print_node(Node *, int);
void print_set(int);
void solve(Node *);
Node *new_node(int, int, char *, bool);
Node *build_expression_tree(char *);
Node *next_operator(int, int, char *);

int main()
{
    char expression[257];
    int i;

    char pilha[260] = {};
    int pilha_size = 0;

    while (scanf(" %[^\n]", expression) != EOF)
    {
        Node *tree = build_expression_tree(expression);

        #ifdef DEBUG
        printf("tree: \n");
        print_node(tree, 0);
        #endif
        
        solve(tree);

        #ifdef DEBUG
        printf("resultado: ");
        print_bits(tree->value);
        printf("\n");
        #endif

        print_set(tree->value);
    }

    return 0;
}

Node *new_node(int start, int end, char *s, bool is_operand)
{
    #ifdef DEBUG
    printf("new node from %d to %d, is_operand = %s\n", start, end, is_operand ? "true" : "false");
    #endif

    int set = 0, i;
    Node *node = &mem_pool[count_mem_pool ++];

    node->is_binary_operator = is_operand;
    node->left_operand = NULL;
    node->right_operand = NULL;

    if (is_operand)
    {
        node->value = s[start];
    }
    else
    {
        for (i = start; i < end; i ++)
            if (isalpha(s[i]))
                set |= 1 << (s[i] - 'A');
        node->value = set;
    }

    #ifdef DEBUG
    printf("value: ");
    if (is_operand) printf("%c", node->value);
    else print_bits(node->value);
    printf("\n");
    #endif

    return node;
}

Node *build_expression_tree(char *expression)
{
    #ifdef DEBUG
    printf("builgind tree for \"%s\"\n", expression);
    #endif

    return next_operator(0, strlen(expression), expression);
}

Node *next_operator(int start_search, int end_search, char *expression)
{
    if (start_search >= end_search)
        return NULL;

    int i;
    int size = (start_search + end_search / 2) + 1;
    int parentheses_depth = 0;
    int operator_index = -1;
    int operator_order = 0;
    int operator_parentheses_depth = size;

    int operator_order_per_parentheses_depth[size];
    memset(operator_order_per_parentheses_depth, 0, sizeof(operator_order_per_parentheses_depth));

    #ifdef DEBUG
    printf("searching next operator from %d to %d\n", start_search, end_search);
    #endif

    // busca dentro do intervalo aquele operador com maior precedência e fora de mais parênteses
    for (i = end_search - 1; i >= start_search; i --)
    {
        parentheses_depth += (expression[i] == ')' ? 1 : expression[i] == '(' ? -1 : 0);

        if (is_operator(expression[i]))
        {
            #ifdef DEBUG
            printf("%c (i=%d) is operator\n", expression[i], i);
            #endif
            operator_order = precedence(expression[i]);
            if (operator_order > operator_order_per_parentheses_depth[parentheses_depth])
            {
                operator_order_per_parentheses_depth[parentheses_depth] = operator_order;

                if (parentheses_depth <= operator_parentheses_depth)
                {
                    operator_index = i;
                    operator_parentheses_depth = parentheses_depth;
                }
            }
        }
    }

    // não há operador no intervalo
    if (operator_index == -1)
    {
        #ifdef DEBUG
        printf("no opertator found\n");
        #endif

        return new_node(start_search, end_search, expression, false);
    }

    #ifdef DEBUG
    printf("opertator found at %d\n", operator_index);
    #endif

    // há operador no intervalo
    Node *node = new_node(operator_index, operator_index + 1, expression, true);

    // operador da esquerda
    int start = start_search + operator_parentheses_depth;
    int end = operator_index;
    node->left_operand = next_operator(start, end, expression);

    // operador da direita
    start = operator_index + 1;
    end = end_search - operator_parentheses_depth;
    node->right_operand = next_operator(start, end, expression);

    return node;
}

int precedence(char c)
{
    return precedende_order[strchr(valid_operators, c) - valid_operators] - '0';
}

bool is_operator(char c)
{
    #ifdef DEBUG
    printf("checking if %c is operator: ");
    char *t = strchr(valid_operators, c);
    if (t) printf("%s\n", t);
    else printf("(null)\n");
    #endif

    return strchr(valid_operators, c) != NULL;
}

void print_node(Node *node, int rank)
{
    if (node == NULL) return;

    for (int i = 0; i < rank; i ++) printf("-"); printf(" ");
    if (node->is_binary_operator) printf("\'%c\': \n", node->value);
    else print_bits(node->value), printf("\n");    

    print_node(node->left_operand, rank + 2);
    print_node(node->right_operand, rank + 2);
}

void print_bits(int n)
{
    do
    {
        printf("%d", n & 1);
        n >>= 1;
    } while (n);
}

void print_set(int set)
{
    char letra = 'A';
    printf("{");
    while (set)
    {
        if (set & 1) printf("%c", letra);
        set >>= 1;
        letra ++;
    }
    printf("}\n");
}

void solve(Node *tree)
{
    if (!tree)
        return;

    if (!tree->is_binary_operator)
        return;

    solve(tree->left_operand);
    solve(tree->right_operand);

    tree->value = apply_operation(tree);
}

int apply_operation(Node *node)
{
    int op1 = node->left_operand->value;
    int op2 = node->right_operand->value;
    int res;

    switch (node->value)
    {
    case '+': res = op1 | op2; break;
    case '-': res = op1 - (op1 & op2); break;
    case '*': res = op1 & op2; break;
    default: break;
    }

    return res;
}

