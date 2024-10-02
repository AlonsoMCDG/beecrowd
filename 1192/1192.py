# bee 1192 - O jogo Matemático de Paula
# Alonso Martins
# 02/10/2024

def jogo_de_paula(x):
    a, b = map(int, x[::2])
    c = x[1]
    
    if a == b: return a * b
    if c.isupper(): return b - a
    return b + a


if __name__ == '__main__':
    n = int(input())
    
    for i in range(n):
        m = input()
        
        print(jogo_de_paula(tuple(m)))
