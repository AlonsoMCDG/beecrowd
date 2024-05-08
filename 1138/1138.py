# bee 1138 - Contagem de Digitos
# Alonso Martins
# 07/05/2024
def contar_digitos(v, n):
    if n <= 0: 
        return

    t1 = t2 = t3 = dig = 0

    # unidades
    for i in range(1, 10):
        v[i] += n // 10 + ((n % 10) >= i)

    v[0] = n // 10 # o zero conta diferente

    # resto das casas
    for i in range(1, 9):
        t1 = 10**i
        t2 = n // (10**(i + 1))
        t3 = (n % t1) + 1
        dig = (n // t1) % 10
        
        if t2 > 1:
            v[0] += (t2 - 1) * t1
        if t2 and dig:
            v[0] += t1
        elif t2 and not dig:
            v[0] += t3
        
        for d in range(1, 10): # conta os dígitos de 1 a 9 na posicao 10^i
            contador = (t2 + (dig > d)) * t1 + t3 * (dig == d)
            v[d] += contador
        
        if (t2 == 0):
            break


while True:
    A, B = map(int, input().split())

    if (A == 0 or B == 0):
        break

    left_bound = [0]*10
    right_bound = [0]*10 
    
    contar_digitos(left_bound, A - 1)
    contar_digitos(right_bound, B)

    for i in range(10):
        print(f"{right_bound[i] - left_bound[i]}", end='\n' if i == 9 else ' ')
