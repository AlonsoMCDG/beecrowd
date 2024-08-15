// bee 1063 - Trilhos Novamente... Tracando Movimentos
// Alonso Martins
// 15/08/2024
#include <stdio.h>
#include <stdbool.h>
#define DEBUG 0
#define debug if (DEBUG)

#define toi(x) (x - 'a')

typedef struct stack
{
    int top;
    int elements[30];
} stack;

void insert(stack *stack, char elemento)
{
    stack->elements[++ stack->top] = elemento;
}

char top(stack *stack)
{
    if (stack->top == -1) return -1;
    return stack->elements[stack->top];
}

char pop(stack *stack)
{
    if (stack->top == -1) return -1;
    return stack->elements[stack->top --];
}

int main()
{
    int N, i, j, t;
    char entrada[100], saida[100];

    while (scanf("%d", &N), N)
    {
        char A[30], B;
        stack pilha = { .top = -1 };
        t = 0;  // quantidade de caracteres na saida

        scanf(" %90[^\n]", entrada);
        debug printf("A = [%s]\n", entrada);

        for (i = 0; i < N; i ++)
        {
            A[i] = entrada[i * 2];
        }

        bool eh_possivel = true;

        scanf(" %90[^\n]", entrada);
        debug printf("B = [%s]\n", entrada);

        for (i = j = 0; i < N; i ++)
        {
            B = entrada[i * 2];

            while (j < N && top(&pilha) != B)
            {
                debug printf("inserting %c\n", A[j]);
                insert(&pilha, A[j ++]);
                saida[t ++] = 'I';
            }

            if (top(&pilha) == B)
            {
                pop(&pilha);
                debug printf("Removed %c\n", B);
                saida[t ++] = 'R';
            }
            else
            {
                eh_possivel = false;
                break;
            }
        }

        saida[t] = '\0';
        printf("%s%s\n", saida, eh_possivel ? "" : " Impossible");
    }

    return 0;
}
