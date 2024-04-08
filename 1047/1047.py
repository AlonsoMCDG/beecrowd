# bee 1047 - Tempo de Jogo com Minutos
# Alonso Martins
# 25/07/2023
hi, mi, hf, mf = input().split()
totalMin = int(hf) * 60 + int(mf) - int(hi) * 60 - int(mi)
if totalMin <= 0:
    totalMin += 24 * 60
horas = totalMin // 60
minutos = totalMin % 60
print(f"O JOGO DUROU {horas} HORA(S) E {minutos} MINUTO(S)")
