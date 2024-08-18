# bee 3053 - Jogo Dos Copos
# Alonso Martins
# 28/08/2023
def troca(x, y):
    a = copos[x]
    copos[x] = copos[y]
    copos[y] = a
    
N = int(input())
moeda = ord(input())-ord('A')
copos = [0, 1, 2]
for i in range(N):
    mov = input()
    if mov == '1':
        troca(0, 1)
    elif mov == '2':
        troca(1, 2)
    else:
        troca(0, 2)
print(chr(copos.index(moeda)+ord('A')))
