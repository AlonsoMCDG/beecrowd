# bee 1024 - Criptografia
# Alonso Martins
# 09/04/2024
T = int(input())
while T > 0:
    txt = input()[::-1]
    size = len(txt)
    R = ""
    for i in range(size):
        c = txt[i]
        c = chr(ord(c) + 3) if c.isalpha() else c
        R += chr(ord(c) - 1) if i >= size // 2 else c
    print(R)
    T -= 1
