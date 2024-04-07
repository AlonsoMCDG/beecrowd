# bee 3161 - As Frutas Esquecidas
# Alonso Martins
# 30/08/2023
N, M = input().split()
testes = []
frutas = []
for n in range(int(N)):
    f = input().lower()
    testes.append(f)
for m in range(int(M)):
    f = input().lower()
    frutas.append(f)

for t in testes:
    res = "detesta"
    for f in frutas:
        if t in f or t[::-1] in f:
            res = "come"
            break
    print(f"Sheldon {res} a fruta {t}")
    
