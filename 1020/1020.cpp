// bee 1020 - Idade em Dias
// Alonso Martins
// 18/04/2024
#include <iostream>

int divmod(int *p, int m)
{
    int x = *p / m;
    *p %= m;
    return x;
}

using namespace std;

int main()
{
    int d;

    cin >> d;
    
    cout << divmod(&d, 365) << " ano(s)\n";
    cout << divmod(&d, 30) << " mes(es)\n";
    cout << d << " dia(s)\n";

    return 0;
}
