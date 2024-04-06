# bee 3208 - O Criptografo Envergonhado
# Alonso Martins
# 05/09/2023
import math
s = input().split()
K, L = [int(x) for x in s]
while K != 0:
    forcaSenha = "GOOD"
    menorL = 0
    for i in range(2, L):
        if K % i == 0:
            if menorL == 0 or i < menorL:
                menorL = i
            forcaSenha = "BAD"
            break
        
    if forcaSenha == "GOOD":
        print(forcaSenha)
    else:
        print(forcaSenha, menorL)
            
    s = input().split()
    K, L = [int(x) for x in s]
