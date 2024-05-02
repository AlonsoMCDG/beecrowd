# bee 1241 - Encaixa ou Nao II
# Alonso Martins
# 03/08/2023
n = int(input())
for i in range(n):
    A, B = input().split()
    print("encaixa" if A.endswith(B) else "nao encaixa")
