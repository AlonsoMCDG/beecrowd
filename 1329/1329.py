# bee 1329 - Cara ou Coroa
# Alonso Martins
# 25/03/2024

from collections import Counter

while True:
	n = int(input())
	
	if n == 0:
		break
	
	jogos = input().split()#map(int, input().split())
	
	wins = Counter(jogos)
	print(f"Mary won {wins['0']} times and John won {wins['1']} times")
