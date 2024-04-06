# bee 3160 - Amigos
# Alonso Martins
# 06/04/2024
N = input()
L = input()
indica = input()
if(indica == "nao"):
    print(N + " " + L)
else:
    idx = N.find(indica)
    print((N[:idx] + L + " " + N[idx:]).strip())
