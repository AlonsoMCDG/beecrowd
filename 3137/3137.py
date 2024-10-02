# bee 3137 - Páginas de um Livro
# Alonso Martins
# 02/10/2024
from math import log10

def contar_digitos_de_1_ate_(n):
    l = len(str(n))
    base = int("09999999"[:l])
    digitos = 0

    for i in range(l-1):
        qtd = 9 * 10**i
        digitos += (i + 1) * qtd
    
    resto = n - base
    digitos += l * resto
    
    return digitos
    
    
if __name__ == '__main__':
    pag = int(input())
    
    print(contar_digitos_de_1_ate_(pag))
