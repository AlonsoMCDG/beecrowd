# bee 1051 - Imposto de Renda
# Alonso Martins
# 25/07/2023
renda = float(input())
taxa = 0.0
if renda > 4500:
    taxa += (renda - 4500) * 0.28
    renda -= renda - 4500
if renda > 3000:
    taxa += (renda - 3000) * 0.18
    renda -= renda - 3000
if renda > 2000:
    taxa += (renda - 2000) * 0.08
    renda -= renda - 2000
print(f"R$ {taxa:.2f}" if taxa > 0 else "Isento")
