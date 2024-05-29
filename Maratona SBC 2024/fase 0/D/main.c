// Maratona SBC 2024 - fase 0
// questão D - Deus-serpente M'boi e as Cataratas do Iguaçu
// Alonso Martins
// 25/05/2024
#include <stdio.h>

int main()
{
    int E, V, T;
    int t, horas = 19, minutos = 0;
    long long tempoEmMinutos, tempoEmHoras;

    scanf("%d %d", &E, &V);

    tempoEmMinutos = 60L * E / V;
    horas = (19L + tempoEmMinutos / 60L) % 24L;
    minutos = tempoEmMinutos % 60L;

    printf("%02d:%02d\n", horas, minutos);

    return 0;
}
