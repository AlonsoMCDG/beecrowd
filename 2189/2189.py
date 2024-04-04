# bee 2189 - Quermesse
# Alonso Martins
# 18/03/2024
t = 0
while True:
	N = int(input())
	
	if N == 0:
		break
	t += 1
	
	ent = list(map(int, input().split()))
	
	i = 0
	
	while ent[i] != i + 1:
		i += 1
	
	print("Teste", t)	
	print(i + 1)
	print()
