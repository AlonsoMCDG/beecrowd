// bee 1090 - Set
// Alonso Martins
// 11/04/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#define CIRCULO 0
#define TRIANGULO 1
#define QUADRADO 2
#define UM 0
#define DOIS 1
#define TRES 2

#define F1 combinacoes_f_e_q_diferentes(cartas_copia)
#define F2 combinacoes_f_diferente_e_q_igual(cartas_copia)
#define F3 combinacoes_f_igual_e_q_diferente(cartas_copia)
#define F4 combinacoes_f_e_q_iguais(cartas_copia)

int menor(int a, int b, int c)
{
    return a <= b && a <= c ? a : b <= a && b <= c ? b : c;
}
int encontrar_menor(int n, int *v)
{
    int i, menor = v[0];
    for (i = 1; i < n; i ++)
        menor = v[i] < menor ? v[i] : menor;
    return menor;
}

int combinacoes_f_e_q_diferentes(int c[3][3])
{
    int i, j, r = 0, aux = 0, a, b;
    for (i = 0; i < 3; i ++)
    {
        a = (i + 1) % 3;
        b = (i + 2) % 3;
        aux = menor(c[CIRCULO][i], c[TRIANGULO][a], c[QUADRADO][b]);
        c[CIRCULO][i]   -= aux;
        c[TRIANGULO][a] -= aux;
        c[QUADRADO][b]  -= aux;
        r += aux;
    }
    for (i = 0; i < 3; i ++)
    {
        a = i - 1, b = i - 2;
        a += a < 0 ? 3 : 0;
        b += b < 0 ? 3 : 0;
        aux = menor(c[CIRCULO][i], c[TRIANGULO][a], c[QUADRADO][b]);
        c[CIRCULO][i]   -= aux;
        c[TRIANGULO][a] -= aux;
        c[QUADRADO][b]  -= aux;
        r += aux;
    }
    return r;
}
int combinacoes_f_diferente_e_q_igual(int c[3][3])
{
    int i, j, r = 0, aux = 0;
    for (i = 0; i < 3; i++)
    {
        aux = menor(c[CIRCULO][i], c[TRIANGULO][i], c[QUADRADO][i]);
        c[CIRCULO][i]   -= aux;
        c[TRIANGULO][i] -= aux;
        c[QUADRADO][i]  -= aux;
        r += aux;
    }
    return r;
}
int combinacoes_f_igual_e_q_diferente(int c[3][3])
{
    int i, j, r = 0, aux = 0;
    for (i = 0; i < 3; i++)
    {
        aux = menor(c[i][UM], c[i][DOIS], c[i][TRES]);
        c[i][UM]   -= aux;
        c[i][DOIS] -= aux;
        c[i][TRES] -= aux;
        r += aux;
    }
    return r;
}
int combinacoes_f_e_q_iguais(int c[3][3])
{
    int i, j, r = 0, aux = 0;
    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            r += c[i][j] / 3;
            c[i][j] %= 3;
        }
    }
    return r;
}

void imprimir(int v[3][3])
{
    int i, j;
    for (i = 0; i < 3; i ++)
        for (j = 0; j < 3; j ++)
            printf("%4d%s", v[i][j], j == 2 ? "\n" : " ");
}

void fazerCopia(int **fonte, int **destino)
{
    int l = sizeof(fonte);
    int c = sizeof(fonte) / sizeof(fonte[0]);
    int i, j;
    for (i = 0; i < l; i ++)
        for (j = 0; j < l; j ++)
            destino[i][j] = fonte[i][j];
}
int combinacoes(int cartas[3][3])
{
    int i, controle = 0, ans, res = 0;
    int cartas_copia[3][3];

    do
    {
        memcpy(cartas_copia, cartas, sizeof(int) * 9);

        switch (controle)
        {
        case 0: // 1 2 3 4
            ans = 0 + F1 + F2 + F3 + F4;
            break;
        case 1: // 1 2 4 3
            ans = 0 + F1 + F2 + F4 + F3;
            break;
        case 2: // 1 3 2 4
            ans = 0 + F1 + F3 + F2 + F4;
            break;
        case 3: // 1 3 4 2
            ans = 0 + F1 + F3 + F4 + F2;
            break;
        case 4: // 1 4 2 3
            ans = 0 + F1 + F4 + F2 + F3;
            break;
        case 5: // 1 4 3 2
            ans = 0 + F1 + F4 + F3 + F2;
            break;
        case 6: // 2 1 3 4
            ans = 0 + F2 + F1 + F3 + F4;
            break;
        case 7: // 2 1 4 3
            ans = 0 + F2 + F1 + F4 + F3;
            break;
        case 8: // 2 3 1 4
            ans = 0 + F2 + F3 + F1 + F4;
            break;
        case 9: // 2 3 4 1
            ans = 0 + F2 + F3 + F4 + F1;
            break;
        case 10: // 2 4 1 3
            ans = 0 + F2 + F4 + F1 + F3;
            break;
        case 11: // 2 4 3 1
            ans = 0 + F2 + F4 + F3 + F1;
            break;
        case 12: // 3 1 2 4
            ans = 0 + F3 + F1 + F2 + F4;
            break;
        case 13: // 3 1 4 2
            ans = 0 + F3 + F1 + F4 + F2;
            break;
        case 14: // 3 2 1 4
            ans = 0 + F3 + F2 + F1 + F4;
            break;
        case 15: // 3 2 4 1
            ans = 0 + F3 + F2 + F4 + F1;
            break;
        case 16: // 3 4 1 2
            ans = 0 + F3 + F4 + F1 + F2;
            break;
        case 17: // 3 4 2 1
            ans = 0 + F3 + F4 + F2 + F1;
            break;
        case 18: // 4 1 2 3
            ans = 0 + F4 + F1 + F2 + F3;
            break;
        case 19: // 4 1 3 2
            ans = 0 + F4 + F1 + F3 + F2;
            break;
        case 20: // 4 2 1 3
            ans = 0 + F4 + F2 + F1 + F3;
            break;
        case 21: // 4 2 3 1
            ans = 0 + F4 + F2 + F3 + F1;
            break;
        case 22: // 4 3 1 2
            ans = 0 + F4 + F3 + F1 + F2;
            break;
        case 23: // 4 3 2 1
            ans = 0 + F4 + F3 + F2 + F1;
            break;
        default:
            break;
        }

        res = fmax(res, ans);
    } while (controle++ < 23);

    return res;
}
int main()
{
    int N, q, f, i, j, ans;
    char quantidade[20], figura[20];
    int cartas[3][3] = {{}};

    while (scanf("%d", &N) && N)
    {
        int cartas[3][3] = {{}};
        for (i = 0; i < N; i ++)
        {
            scanf(" %s %s", quantidade, figura);

            switch (quantidade[0])
            {
                case 'u': q = UM;   break;
                case 'd': q = DOIS; break;
                case 't': q = TRES; break;
                default: break;
            }
            switch (figura[0])
            {
                case 'c': f = CIRCULO;   break;
                case 't': f = TRIANGULO; break;
                case 'q': f = QUADRADO;  break;
                default: break;
            }

            cartas[f][q]++;
        }

        ans = combinacoes(cartas);

        printf("%d\n", ans);
    }

    return 0;
}
