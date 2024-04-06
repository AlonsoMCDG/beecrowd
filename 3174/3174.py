# bee 3174 - Grupo de Trabalho do Noel
# Alonso Martins
# 05/09/2023
N = int(input())
horas = [0,0,0,0]
trabalho = [8, 4, 6, 12]
presntes = 0
for i in range(N):
    s = input().split()
    grupo = s[1]
    hrs = int(s[2])
    if grupo == "bonecos":
        horas[0] += hrs
    elif grupo == "arquitetos":
        horas[1] += hrs
    elif grupo == "musicos":
        horas[2] += hrs
    else:
        horas[3] += hrs
for i in range(4):
    presntes += horas[i]//trabalho[i]

print(presntes)
