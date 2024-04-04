# bee 2321 - Detectando Colisoes
# Alonso Martins
# 13/03/2024
x11, y11, x21, y21 = map(int, input().split())
x12, y12, x22, y22 = map(int, input().split())
print(1 if not(x11 > x22 or y11 > y22 or x21 < x12 or y21 < y12) else 0)
