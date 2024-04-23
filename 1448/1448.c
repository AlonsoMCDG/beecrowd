// bee 1448 - Telefone Sem Fio
// Alonso Martins
// 23/04/2024
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 102

int main()
{
    char frase_correta[MAX_LENGTH];
    char frase_time1[MAX_LENGTH];
    char frase_time2[MAX_LENGTH];
    int t, instancia_atual, i, len, desempate;
    int t1d, t2d, p1, p2;
    scanf("%d ", &t);

    for (instancia_atual = 1; instancia_atual <= t; instancia_atual ++)
    {
        desempate = 0; p1 = 0; p2 = 0;

        fgets(frase_correta, MAX_LENGTH, stdin);
        fgets(frase_time1, MAX_LENGTH, stdin);
        fgets(frase_time2, MAX_LENGTH, stdin);

        len = strlen(frase_correta);
        
        frase_correta[len - 1] = '\0';
        frase_time1[len - 1] = '\0';
        frase_time2[len - 1] = '\0';
        
        // printf("fc = %s\n", frase_correta);
        // printf("t1 = %s\n", frase_time1);
        // printf("t2 = %s\n", frase_time2);

        for (i = 0; i < len; i ++)
        {
            // printf("----\n");
            // printf("fc[%d] = %c\n", i, frase_correta[i]);
            // printf("t1[%d] = %c\n", i, frase_time1[i]);
            // printf("t2[%d] = %c\n", i, frase_time2[i]);

            t1d = frase_correta[i] == frase_time1[i];
            t2d = frase_correta[i] == frase_time2[i];

            p1 += t1d;
            p2 += t2d;

            // printf("td1 = %d, td2 = %d\n", t1d, t2d);
            // printf("p1 = %d, p2 = %d\n", p1, p2);

            if (!desempate)
            {
                desempate = 1 * (t1d && !t2d) + 2 * (!t1d && t2d);

                // if (t1d && !t2d)
                //     desempate = 1;
                // else if (t2d && !t1d)
                //     desempate = 2;
            }

            // printf("desempate = %d\n", desempate);
        }

        printf("Instancia %d\n", instancia_atual);

        // printf("p1 = %d, p2 = %d\n", p1, p2);
        // printf("desempate = %d\n", desempate);
        if (p1 == p2)
        {
            if (desempate)
                printf("time %d\n", desempate);
            else
                printf("empate\n");
        } else {
            printf("time %d\n", p1 > p2 ? 1 : 2);
        }
        
        printf("\n");
    }
    
    return 0;
}
