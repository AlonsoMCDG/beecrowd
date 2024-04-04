# bee 1120 - Revisao de Contrato
# Alonso Martins
# 13/12/2023
D, N = input().split()
while (D != '0' or N != '0'):
    N = N.replace(D, "")
    if N == "":
        N = "0"
    else:
        N = int(N)
    print(N)
    D, N = input().split()
