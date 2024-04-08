# bee 2534 - Exame Geral
# Alonso Martins
# 07/08/2023
while True:
    try:
        N, Q = input().split()
        notas = []
        for i in range(int(N)):
            notas.append(int(input()))
        notas.sort(reverse = True)
        for i in range(int(Q)):
            print(notas[int(input())-1])
    except EOFError:
        break
