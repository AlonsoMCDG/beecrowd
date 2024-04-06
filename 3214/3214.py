# bee 3214 - Refrigerante
# Alonso Martins
# 05/09/2023
s = input().split()
E, F, C = [int(x) for x in s]
R = 0
while E + F >= C:
    E += F
    F = E // C
    E %= C
    R += F
print(R)
