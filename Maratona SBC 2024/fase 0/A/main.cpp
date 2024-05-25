// questão A - Alice e as Canções de Iara
// Se contente com 3
// 25/05/2024
#include <bits/stdc++.h>
using namespace std;
int main(){
    int v;
    int cansoes[4];
    memset(cansoes, 0, sizeof(cansoes));
    for (int i = 0; i < 3; i++){
        cin >> v;
        cansoes[v-1] = 1;
    }
    for (int i = 0; i < 3; i++) if (!cansoes[i]) cout << i+1 << "\n";
    return 0;
}
