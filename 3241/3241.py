# bee 3241 - Ajude um Candidato a PhD!
# Alonso Martins
# 11/09/2023
N = int(input())
for i in range(N):
    s = input()
    if s == "P=NP":
        print("skipped")
        continue
    s = s.split("+")
    print(int(s[0])+int(s[1]))
