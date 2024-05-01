# bee 1101 - Sequência de Números e Soma
# Alonso Martins
# 01/05/2024
while True:
    M, N = map(int, input().split())
    if M < 1 or N < 1:
        break
    if M > N:
        M, N = N, M
    sum = 0
    for n in range(M, N + 1):
        sum += n
        print(n, end=" ")
    print(f"Sum={sum}")
