// bee 1222 - Concurso de Contos
// Alonso Martins
// 02/05/2024
#include <iostream>

using namespace std;

int main()
{
    int N, L, C, i;
    int caracteres, linhas, paginas, len;
    string palavra;

    while (cin >> N >> L >> C)
    {
        caracteres = 0; linhas = paginas = 1;

        for (i = 0; i < N; i ++)
        {
            cin >> palavra; 
            len = palavra.length();
            caracteres += len + 1;

            if (caracteres - 1 > C)
            {
                caracteres = len + 1;
                linhas ++;
            }
            if (linhas > L)
            {
                linhas = 1;
                paginas ++;
            }
        }

        cout << paginas << "\n";
    }

    return 0;
}
