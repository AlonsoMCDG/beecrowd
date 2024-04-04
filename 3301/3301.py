# bee 3301 - Sobrinho do Meio
# Alonso Martins
# 07/02/2024
idades = list(map(int, input().split()))
nomes = ["huguinho", "zezinho", "luisinho"]
info = [[idades[i], nomes[i]] for i in range(3)]
info.sort(key=lambda x: x[0])
print(info[1][1])
