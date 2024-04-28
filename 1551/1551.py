# bee 1551 - Frase Completa
# Alonso Martins
# 10/08/2023
N = int(input())
a = "abcdefghijklmnopqrstuvwxyz"
ok = 0
for i in range(N):
    ok = 0
    f = input().lower()
    for c in a:
        if c in f:
            ok += 1
    print("frase completa" if ok == 26 else "frase mal elaborada" if ok <= 14 else "frase quase completa")

