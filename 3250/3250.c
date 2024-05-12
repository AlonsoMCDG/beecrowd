// bee 3250 - Problema no Eleveador
// Alonso Martins
// 11/05/2024
#include <stdio.h>
#include <math.h>

int target(int f, int s, int g, int u, int d)
{
    int visitado[f], i;
    int passos = 0, p, podeSubir, podeDescer;

    for (i = 0; i < f; i ++)
        visitado[i] = 0;

    while (1)
    {
        podeSubir = s + u <= f && u;
        podeDescer = s - d >= 1 && d;

        if (s == g) 
            break;

        if (!podeSubir && !podeDescer || visitado[s - 1]) 
            return -1;

        visitado[s - 1] = 1;

        if (s < g)
        {
            if (podeSubir)
            {
                p = ceil((g - s) / (double)u);
                if (s + p * u <= f || -- p && s + p * u <= f)
                {
                    s += p * u;
                    passos += p;
                }
            }
            else if (podeDescer)
            {
                p = ceil(((s + u) % f) / (double)d);
                if (s - p * d >= 1)
                {
                    s -= p * d;
                    passos += p;
                }
                else
                {
                    return -1;
                }
            }
        }
        else if (s > g)
        {
            if (podeDescer)
            {
                p = ceil((s - g) / (double)d);
                if (s - p * d >= 1 || -- p && s - p * d >= 1)
                {
                    s -= p * d;
                    passos += p;
                }
            }
            else if (podeSubir)
            {
                p = ceil((abs(s - d - 1)) / (double)u);
                if (s + p * u <= f || -- p && s + p * u <= f)
                {
                    s += p * u;
                    passos += p;
                }
            }
        }
        else
        {
            return -1;
        }
    }

    return passos;
}

int main()
{
    int f, s, g, u, d, ans;

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    ans = target(f, s, g, u, d);

    printf(ans + 1 ? "%d\n" : "use the stairs\n", ans);

    return 0;
}
