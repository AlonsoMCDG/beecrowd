# bee 1534 - Matriz 123
# Alonso Martins
# 16/08/2024
while True:
    try:
        n = int(input())
        for i in range(n):
            s = ""
            for j in range(n):
                if i + j == n - 1: s += "2"
                elif i == j: s += "1"
                else: s += "3"
            print(s)
    except EOFError:
        break
