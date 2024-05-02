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

        for (i = 0; i < len; i ++)
        {
            t1d = frase_correta[i] == frase_time1[i];
            t2d = frase_correta[i] == frase_time2[i];

            p1 += t1d;
            p2 += t2d;

            if (!desempate)
            {
                desempate = 1 * (t1d && !t2d) + 2 * (!t1d && t2d);
            }
        }

        printf("Instancia %d\n", instancia_atual);
      
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
