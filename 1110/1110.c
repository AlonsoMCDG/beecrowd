// bee 1110 - Jogando Cartas Fora
// Alonso Martins
// 05/08/2024
#include <stdio.h>
#include <stdlib.h>

enum states
{
    REMOVE,
    PUT_UNDER
};

typedef struct Card
{
    int num;
    struct Card *next;
    struct Card *prev;
} Card;

int main()
{
    int N, i;
    Card * cards_memory_pool[51];

    for (i = 0; i < 51; i ++)
        cards_memory_pool[i] = (Card *)malloc(sizeof(Card));

    while (scanf("%d", &N), N)
    {
        Card *prev = NULL;
        for (i = 0; i < N; i ++)
        {
            cards_memory_pool[i]->num = i + 1;
            cards_memory_pool[i]->next = i + 1 < N ? cards_memory_pool[i + 1] : NULL;
            cards_memory_pool[i]->prev = prev;
            prev = cards_memory_pool[i];
        }

        Card *stack_top = cards_memory_pool[0];
        Card *stack_bottom = cards_memory_pool[N - 1];
        Card *prev_top = NULL;
        int state = REMOVE;

        while (stack_top != stack_bottom)
        {
            if (state == REMOVE)
            {
                if (prev_top) prev_top->next = stack_top;

                prev_top = stack_top;
                stack_top = stack_top->next;
            }
            else
            {
                Card *next = stack_top->next;

                stack_bottom->next = stack_top;
                stack_bottom = stack_top;

                stack_top = next;
            }

            state = ++ state % 2;
        }

        Card *curr = cards_memory_pool[0];

        printf("Discarded cards:");
        while (-- N)
        {
            printf("%s %d", curr->num == 1 ? "" : ",", curr->num);
            curr = curr->next;
        }

        printf("\nRemaining card: %d\n", stack_top->num);
    }


    return 0;
}
