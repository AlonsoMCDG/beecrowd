# bee 2469 - Notas
# Alonso Martins
# 07/08/2024
N = int(input())
notas = [int(x) for x in input().split()]
notas.sort(reverse=True)
maiorFreq = 1
ans = notas[0]
freq = 1

for i in range(1, N):
    if notas[i] == notas[i - 1]:
        freq += 1
        if freq > maiorFreq:
            maiorFreq = freq
            ans = notas[i]
    else:
        freq = 1
    if N - i < freq:
        break

print(ans)
