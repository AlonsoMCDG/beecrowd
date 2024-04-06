# bee 3209 - Tomadas Eletricas
# Alonso Martins
# 05/09/2023
N = int(input())
for i in range(N):
    s = input().split()
    s = [int(x) for x in s[1:]]
    tomadas = sum(s) - len(s) + 1
    print(tomadas)
