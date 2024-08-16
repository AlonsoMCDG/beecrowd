# bee 1533 - Detetive Watson
# Alonso Martins
# 15/08/2024
n = int(input())
while n:
    s = list(map(int, input().split()))
    m = [[0, 0]] * 2
    for i in range(n):
        if s[i] > m[0][0]:
            m[1] = m[0][:]
            m[0] = [s[i], i]
        elif s[i] > m[1][0]:
            m[1] = [s[i], i]
    print(m[1][1] + 1)
    n = int(input())
