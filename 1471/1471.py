# bee 1471 - Megulho
# Alonso Martins
# 17/03/2024

while True:
    try:
        N = int(input().split()[0])
        R = map(int, input().split())
        d = sorted(list(set(range(1, N+1)).difference(set(R))))
        
        print(' '.join(map(str, d))+" " if d else "*")
    except EOFError:
        break
