# bee 3249 - Death Knight Hero
# Alonso Martins
# 11/09/2023
N = int(input())
vitorias = 0
for i in range(N):
    s = input()
    if "CD" not in s:
        vitorias += 1
print(vitorias)
