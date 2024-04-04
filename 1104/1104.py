# bee 1104 - Troca de Cartas
# Alonso Martins
# 04/04/2024
A, B = map(int, input().split())
while A + B:
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    at = a.difference(b)
    bt = b.difference(a)
    t = min(len(at), len(bt))
    print(t)
    A, B = map(int, input().split())

