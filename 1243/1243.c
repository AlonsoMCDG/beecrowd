// bee 1243 - O quao facil e...
// Alonso Martins
// 27/04/2024
#include <stdio.h>
#include <ctype.h>

int main() {
    int enunciado, anterior = ' ';
    int i = 0, leitura;
    int qtd_palavras = 0, sum_comprimento = 0, comprimento_palavra = 0, comprimento_medio;
    int palavra_iniciada = 0, palavra_invalida = 0;
    int caso = 0;

    while (1) 
    {
        // if (!i) printf("***** caso %d *****\n", ++caso);

        leitura = (enunciado = getchar());

        // printf("char[%d] = %c", i, enunciado == '\n' ? ' ' : enunciado);

        if(leitura != EOF && enunciado != '\n')
        {
            if (isalpha(enunciado)) {
                // printf(" - isaplha");
                if ((!palavra_iniciada && !palavra_invalida) || anterior == ' ') {
                    // printf(" - nova palavra");
                    palavra_iniciada = 1;
                    palavra_invalida = 0;
                    qtd_palavras++;
                    comprimento_palavra = 1;
                } else {
                    // printf(" - continuacao");
                    comprimento_palavra++;
                }
                // printf(" - comprimento %d\n", comprimento_palavra);
            } else if (enunciado == ' ') {
                // printf(" - espaco");
                if (palavra_iniciada)
                {
                    // printf(" - fim palavra");
                    if (palavra_invalida)
                    {
                        // printf(" - invalida");
                        qtd_palavras--;
                    }
                    else
                    {
                        // printf(" - valida");
                        sum_comprimento += comprimento_palavra;
                    }
                }
                // printf(" - total %d - soma %d\n", qtd_palavras, sum_comprimento);

                palavra_iniciada = 0;
            } else if (isdigit(enunciado) || enunciado == '.' && !isalpha(anterior)) {
                // printf(" - palavra invalida\n");
                palavra_invalida = 1;
            }
            i ++;
            anterior = enunciado;
            continue;
        }
        // printf(" - fim do enunciado");
        if (palavra_iniciada){
            // printf(" - fim palavra");
            if (palavra_invalida) {
                // printf(" - invalida");
                qtd_palavras--;
            }else{
                // printf(" - valida");
                sum_comprimento += comprimento_palavra;
            }
        }

        if (leitura == EOF)
            break;
        
        // printf(" - total %d - soma %d\n", qtd_palavras, sum_comprimento);

        comprimento_medio = qtd_palavras ? sum_comprimento / qtd_palavras : 0;

        // printf("comprimento medio = %d\n", comprimento_medio);
        
        printf("%d\n", comprimento_medio <= 3 ? 250 : comprimento_medio <= 5 ? 500 : 1000);

        // printf("\n\n\n");
        
        i = qtd_palavras = sum_comprimento = comprimento_palavra = palavra_iniciada = palavra_invalida = 0;
    }

    return 0;
}
