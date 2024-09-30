// bee 1119 - A Fila de Desempregados
// Alonso Martins
// 28/09/2024
#include <stdio.h>

typedef struct Node
{
    int id;
    struct Node *next;
    struct Node *prev;
} Node;

Node mem_pool[20];

Node *new_linked_list(int size)
{
    int i;
    Node *linked_list = &mem_pool[0];
    Node *node = linked_list;

    for (i = 0; i < size; i ++)
    {
        int nxt = (i + 1) % size, prv = (size + i - 1) % size;

        node->id = i + 1;
        node->next = &mem_pool[nxt];
        node->prev = &mem_pool[prv];

        node = node->next;
    }

    return linked_list;
}

int main()
{
    int N, K, M, i, j, passos, flag;
    int control;

    while (scanf("%d %d %d", &N, &K, &M), N)
    {
        Node *vitima1 = new_linked_list(N);
        Node *vitima2 = vitima1->prev;
        Node *aux;
        flag = 0;

        while (N)
        {

            passos = (K % N) + K * !(K % N);
            for (i = 1; i < passos; i ++)
                vitima1 = vitima1->next;

            passos = (M % N) + M * !(M % N);
            for (i = 1; i < passos; i ++)
                vitima2 = vitima2->prev;

            if (vitima1->id == vitima2->id)
            {
                aux = vitima1;

                vitima1 = vitima1->next;
                vitima2 = vitima2->prev;

                vitima1->prev = vitima2;
                vitima2->next = vitima1;

                printf("%s%3d", flag ? "," : "", aux->id);
                N --;
            }
            else
            {
                printf("%s%3d%3d", flag ? "," : "", vitima1->id, vitima2->id);

                if (vitima1->prev == vitima2)
                { // [..., vitima2 , vitima1 , ...]
                    vitima2->prev->next = vitima1->next;
                    vitima1->next->prev = vitima2->prev;

                    vitima1 = vitima1->next;
                    vitima2 = vitima2->prev;
                }
                else if (vitima1->next == vitima2)
                { // [..., vitima1 , vitima2 , ...]
                    vitima1->prev->next = vitima2->next;
                    vitima2->next->prev = vitima1->prev;

                    vitima1 = vitima2->next;
                    vitima2 = vitima1->prev;
                }
                else
                { // [..., vitima1, ..., vitima2, ...]
                    vitima1->prev->next = vitima1->next;
                    vitima1->next->prev = vitima1->prev;
                    vitima1 = vitima1->next;

                    vitima2->prev->next = vitima2->next;
                    vitima2->next->prev = vitima2->prev;
                    vitima2 = vitima2->prev;
                }

                N -= 2;
            }


            flag = 1;
        }

        printf("\n");
    }

    return 0;
}
