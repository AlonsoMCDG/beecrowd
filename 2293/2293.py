# bee 2293 - Campo de Minhocas
# Alonso Martins
# 18/08/2024
L, C = map(int, input().split())
linhas = []
colunas = [0] * C

for _ in range(L):
    inp = [int(x) for x in input().split()]
    linhas.append(sum(inp))
    for __ in range(C):
        colunas[__] += inp[__]

print(max(*linhas, *colunas))
