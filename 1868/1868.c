// bee 1868 - Espiral Quadrada
// Alonso Martins
// 30/05/2024
#include <stdio.h>

int main()
{
    int N, t, i, j;
    struct Bob { int linha, coluna, direcao, passos, contPassos, voltas; } bob;
    int movimento[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    char linhas[][30] = {"O", "OOO", "OOOOO", "OOOOOOO", "OOOOOOOOO", "OOOOOOOOOOO", "OOOOOOOOOOOOO", "OOOOOOOOOOOOOOO", "OOOOOOOOOOOOOOOOO", "OOOOOOOOOOOOOOOOOOO", "OOOOOOOOOOOOOOOOOOOOO", "OOOOOOOOOOOOOOOOOOOOOOO", "OOOOOOOOOOOOOOOOOOOOOOOOO"};
    
    while (scanf("%d", &N), N)
        for (bob.linha = bob.coluna = N / 2, bob.passos = 1, bob.voltas = bob.contPassos = bob.direcao = t = 0; bob.contPassos ++, t < N * N; t ++, printf("@\n"))
        {
            for (i = 0; i < N; i ++, printf("\n"))
            {
                if (i == bob.linha)
                    linhas[N / 2][bob.coluna] = 'X';
                    
                printf("%s", linhas[N / 2]);


                linhas[N / 2][bob.coluna] = 'O';
            }
            
            bob.linha += movimento[bob.direcao][0];
            bob.coluna += movimento[bob.direcao][1];

            if (bob.contPassos == bob.passos)
            {
                bob.contPassos = 0;
                bob.direcao = (bob.direcao + 1) % 4;

                if (++ bob.voltas == 2)
                    bob.passos ++, bob.voltas = 0;
            }
        }

    return 0;
}
