# bee 3162 - Comunicacao Espacial
# Alonso Martins
# 30/08/2023
import math as m
N,n=int(input()),[]
for i in range(N):
    c=input().split()
    n.append([int(x)for x in c])
for i in range(N):
    d=m.inf
    for j in range(N):
        if i==j:
            continue
        d=min(d,m.dist(n[i], n[j]))
    print("B"if d>50 else"M"if d>20 else"A")
