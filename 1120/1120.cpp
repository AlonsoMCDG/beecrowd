// bee 1120 - Revisao de Contrato
// Alonso Martins
// 13/12/2024
#include <stdio.h>
#include <string.h>

int main() {
    char D, N[101], Resultado[101];                                     // duas variáveis de entrada e uma para o resultado
    while(scanf(" %c %[^\n]", &D, N) && (D != '0' or strcmp(N, "0") != 0)) { // faz a leitura e compara se a entrada != (0 0)
        int l = 0;                                                      // variável auxiliar para a última posição livre do vetor Resultado
        int lenN = static_cast<int>(strlen(N));                         // typecast de size_t para int de strlen(Resultado)
        for(int i = 0; i < lenN; i ++)                                  // iteração pelo vetor N
            if(N[i] != D and !(N[i] == '0' and l == 0))                 // checa se N[i] != D e também se N[i] não é zero à esquerda de Resultado
                Resultado[l++] = N[i];                                  // se a condição é satisfeita, concatena N[i] para o fim de Resultado
        Resultado[l] = '\0';                                            // adiciona o caractere terminador no fim da string Resultado
        int lenResultado = static_cast<int>(strlen(Resultado));         // typecast de size_t para int de strlen(Resultado)
        if(lenResultado == 0) printf("0\n");                            // checa se o Resultado é 0 (string vazia)
        else printf("%s\n", Resultado);                                 // Se o resultado não é vazio, imprima-o
    }
    return 0;
}
