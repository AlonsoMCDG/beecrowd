# 2420 - Guerra por Territorio
# Alonso Martins
# 17/03/2024
N = int(input())
t = list(map(int, input().split()))
total = sum(t) 
i = 0
t1 = 0
while t1 != total / 2:
	t1 += t[i]
	i += 1
print(i)
