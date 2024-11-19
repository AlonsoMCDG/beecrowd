// bee 1077 - Infixa para Posfixa
// Alonso Martins
// 18/11/2024
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 300

typedef struct Node
{
    char operator[300];
    int rank;
    struct Node *left_operand;
    struct Node *right_operand;
} Node;

enum
{
    LEFT_BOUND = 0,
    RIGHT_BOUND = 1,
    INVALID_INDEX = -1,
    UNDEFINED_ORDER = 0
};

int get_operator_order(char operator)
{
    switch (operator)
    {
    case '^': return 1;
    case '/': return 2;
    case '*': return 2;
    case '+': return 3;
    case '-': return 3;
    default: return UNDEFINED_ORDER;
    }
}

bool is_binary_operator(char c)
{
    return strchr("+-*/^", c) != NULL;
}

// string range copy
void strrcpy(char *dest, char *font, int start, int end)
{
    int i = 0, sz = 0;

    for (i = 0; start < end; start ++)
    {
        if (font[start] == '(' || font[start] == ')')
            continue; // ignore parentheses

        dest[i ++] = font[start];
    }
    dest[i] = '\0';
}

Node nodes[MAX_NODES];
int num_nodes = 0;

Node *new_node(int start, int end, char *operator, int rank)
{
    Node *node = &nodes[num_nodes ++];

    strrcpy(node->operator, operator, start, end);
    node->rank = rank;
    node->left_operand = NULL;
    node->right_operand = NULL;

    return node;
}

Node *next_operator(int start_search, int end_search, char *expression, int rank)
{
    // printf("search = [%d:%d], rank = %d\n", start_search, end_search, rank); // debug
    // printf("\""); for (int i = start_search; i < end_search; i ++) printf("%c", expression[i]); printf("\"\n"); // debug

    if (start_search >= end_search) return NULL;

    int i, operand_has_parentheses = false;
    int size = (end_search - start_search) / 2 + 1;
    int operator_index = INVALID_INDEX;
    int operator_order = UNDEFINED_ORDER;
    int operator_parentheses_depth = size;

    int parentheses_depth = 0;
    int operator_index_per_parentheses_depth[size];
    int operator_order_per_parentheses_depth[size];
    memset(operator_order_per_parentheses_depth, 0, sizeof(operator_order_per_parentheses_depth));

    for (i = end_search - 1; i >= start_search; i --)
    {
        parentheses_depth += (expression[i] == ')' ? 1 : expression[i] == '(' ? -1 : 0);

        if (is_binary_operator(expression[i]))
        {
            operator_order = get_operator_order(expression[i]);
            if (operator_order > operator_order_per_parentheses_depth[parentheses_depth])
            {
                operator_index_per_parentheses_depth[parentheses_depth] = i + 1;
                operator_order_per_parentheses_depth[parentheses_depth] = operator_order;

                if (parentheses_depth <= operator_parentheses_depth)
                {
                    operator_index = i;
                    operator_parentheses_depth = parentheses_depth;
                }
            }
        }
    }

    if (operator_index == INVALID_INDEX)
    {
        // printf("no binary operator was found in the interval\n"); // debug
        return new_node(start_search, end_search, expression, rank);
    }

    // printf("operator_index = %d, operator_order = %d\n", operator_index, operator_order); // debug
    // printf("operator: %c\n", expression[operator_index]); // debug

    Node *node = new_node(operator_index, operator_index + 1, expression, rank);

    // get left operand
    int start = start_search + operator_parentheses_depth;
    int end = operator_index;
    node->left_operand = next_operator(start, end, expression, rank + 1);

    // get right operand
    start = operator_index + 1;
    end = end_search - operator_parentheses_depth;
    node->right_operand = next_operator(start, end, expression, rank + 1);

    return node;
}

void tab(int n)
{
    for (int i = 0; i < n; i ++)
        printf("-");
}

void print_node(Node *node, int rank)
{
    if (node == NULL) return;

    tab(rank);
    printf("\'%s\': rank=%d\n", node->operator, node->rank);
    print_node(node->left_operand, rank + 4);
    print_node(node->right_operand, rank + 4);
}

void posfix(Node *node)
{
    if (node == NULL) return;

    posfix(node->left_operand);
    posfix(node->right_operand);

    printf("%s", node->operator);
}

void solve(Node *tree)
{
    num_nodes = 0;
    posfix(tree);
    printf("\n");
}

Node *build_expression_tree(char *expression)
{
    return next_operator(0, strlen(expression), expression, 0);
}

int main()
{
    int N, i, start, end;
    char expression[302];

    scanf("%d", &N);

    while (N -- && scanf(" %s", expression))
    {
        Node *tree = build_expression_tree(expression);
        solve(tree);
    }
    
    return 0;
}
