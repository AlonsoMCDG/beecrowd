# bee 1238 - Combinador
# Alonso Martins
# 03/08/2023
n = int(input())
for i in range(n):
    s1, s2 = input().split()
    j = 0
    for j in range(min(len(s1), len(s2))):
        print(s1[j]+s2[j], end="")
    print(s1[j+1:] if len(s1) > len(s2) else s2[j+1:])
