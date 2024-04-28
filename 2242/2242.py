# bee 2242 - Huaauhahhuahau
# Alonso Martins
# 25/07/2023
risada = list(input())
risadaAux = ""
for letra in risada:
    if letra in ("a", "e", "i", "o", "u"):
        risadaAux += letra

print("S" if risadaAux == risadaAux[::-1] else "N")
