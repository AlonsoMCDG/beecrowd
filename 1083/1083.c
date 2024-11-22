// bee 1083 - LEXSIM - Avaliador Lexico e Sintatico
// Alonso Martins
// 22/11/2024
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 3000
#define NO_ERRORS 0
#define SYNTAX_ERROR 1
#define LEXICAL_ERROR 2
#define OPERAND 1
#define OPERATOR 2

char stack[MAX_LEN];
int stack_top = 0;
char valid_operators[]  = "^*/+-><=#.|";
char precedende_order[] = "655443333210";
char *error_message[] = {"", "Syntax Error!", "Lexical Error!"};

void push(char);
char pop();
char top();
void clear_stack();
bool is_operand(char);
bool is_operator(char);
bool is_valid_symbol(char);
int has_lexical_errors(char *);
int symbol_type(char);
int precedence(char);
int evaluate(char *, char *, int *);
void solve(char *);

int main()
{
    char expression[MAX_LEN];

    while (scanf(" %s", expression) != EOF)
    {
        // printf("%s\n", expression); // debug
        solve(expression);
        // printf("\n-------\n"); // debug
    }
    
    return 0;
}

void push(char c)
{
    stack[stack_top ++] = c;
}

char pop()
{
    return stack_top ? stack[-- stack_top] : 0;
}

char top()
{
    return stack_top ? stack[stack_top - 1] : 0;
}

void clear_stack()
{
    stack_top = 0;
}

bool is_operand(char c)
{
    return isalnum(c);
}

bool is_operator(char c)
{
    return strchr(valid_operators, c) != NULL;
}

bool is_valid_symbol(char c)
{
    return is_operand(c) || is_operator(c) || c == '(' || c == ')';
}

int has_lexical_errors(char *expression)
{
    int i; char c;

    for (i = 0; c = expression[i]; i ++)
        if (!is_valid_symbol(c))
            return LEXICAL_ERROR;

    return NO_ERRORS;
}

int symbol_type(char c)
{
    return is_operand(c) ? OPERAND : is_operator(c) ? OPERATOR : -1;
}

int precedence(char c)
{
    return precedende_order[strchr(valid_operators, c) - valid_operators] - '0';
}

int evaluate(char *expression, char *output, int *output_size)
{
    char c, p;
    int i, prev = 0;

    if (has_lexical_errors(expression))
        return LEXICAL_ERROR;

    clear_stack();

    for (i = 0; c = expression[i]; i ++)
    {
        if (symbol_type(c) == prev && c != '(' && c != ')')
            return SYNTAX_ERROR;

        prev = (symbol_type(c));

        if (is_operand(c)) // OPERAND
        {
            output[(*output_size) ++] = c;
            if ((i && expression[i - 1] == ')') || expression[i + 1] == '(')
                return SYNTAX_ERROR;

            if (i && (!is_operator(expression[i - 1]) && expression[i - 1] != '('))
                return SYNTAX_ERROR;
        }
        else if (c == '(')
        {
            if (i && expression[i - 1] == ')')
                return SYNTAX_ERROR;

            push('(');
        }
        else if (c == ')')
        {
            if (i && expression[i - 1] == '(') // "()"
                return SYNTAX_ERROR;

            while (c = pop(), c != '(')
            {
                output[(*output_size) ++] = c;

                if (!c) // pilha vazia
                    return SYNTAX_ERROR;
            }
        }
        else // OPERATOR
        {
            if (i == 0 || expression[i - 1] == '(' || is_operator(expression[i + 1]) || expression[i + 1] == ')' || expression[i + 1] == '\0')
                return SYNTAX_ERROR;

            while (p = top(), p && p != '(' && precedence(c) <= precedence(p))
                output[(*output_size) ++] = pop();
            push(c);
        }
    }

    while (c = pop())
    {
        if (c == '(')
            return SYNTAX_ERROR;

        output[(*output_size) ++] = c;
    }

    output[(*output_size)] = '\0';

    return NO_ERRORS;
}

void solve(char *expression)
{
    char output[MAX_LEN];
    int i, output_size = 0, error = NO_ERRORS;

    if ((error = evaluate(expression, output, &output_size)) == NO_ERRORS)
        printf("%s\n", output);
    else
        printf("%s\n", error_message[error]);
}
