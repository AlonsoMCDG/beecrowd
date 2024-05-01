// bee 1101 - Sequência de Números e Soma
// Alonso Martins
// 01/05/2024
#include <bits/stdc++.h>

using namespace std;

int soma_sequencia(int start, int end)
{
    printf("%d ", start);
    return start == end ? end : start + soma_sequencia(start + 1, end);
}

int main()
{
    int a, b, sum;

    while (scanf("%d %d", &a, &b) && a > 0 && b > 0)
    {
        sum = soma_sequencia(min(a, b), max(a, b));
        cout << "Sum=" << sum << "\n";
    }
    
    return 0;
}
