# bee 1533 - Detetive Watson
# Alonso Martins
# 15/08/2024
n = int(input())
while n:
    s = list(map(int, input().split()))
    s = [[i + 1, s[i]] for i in range(n)]
    s.sort(key=lambda x : x[1])    
    print(s[-2][0])
    n = int(input())
