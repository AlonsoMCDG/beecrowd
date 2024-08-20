# bee 2378 - Elevador
# Alonso Martins
# 19/08/2024
N, capacidadeMaxima = map(int, input().split())
noElevador = 0
ultrapassou = False

while N:
    o, i = map(int, input().split())
    noElevador += i - o

    if noElevador > capacidadeMaxima:
        ultrapassou = True
        break

    N -= 1

print("S" if ultrapassou else "N")
