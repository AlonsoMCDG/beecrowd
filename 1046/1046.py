# bee 1046 - Tempo de Jogo
# Alonso Martins
# 25/07/2023
inicio, fim = input().split()
duracao = int(fim) - int(inicio)
duracao += 0 if duracao > 0 else 24
print(f"O JOGO DUROU {duracao} HORA(S)")
