# bee 1171 - Frequencia de Numeros
# Alonso Martins 
# 17/03/2024

t = int(input())
nums = {}
for i in range(t):
	n = input()
	nums[n] = nums.setdefault(n, 0) + 1
for k in sorted(nums.keys(), key=int):
	print(f'{k} aparece {nums[k]} vez(es)')
