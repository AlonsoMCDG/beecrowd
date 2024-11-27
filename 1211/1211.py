# bee 1211 - Lista Telefonica Economica
# Alonso Martins
# 27/11/2024
while True:
    try:
        N = int(input())
        tel = sorted([input() for _ in range(N)])
        ans = 0
        for i in range(1, N):
            for j in range(len(tel[0])):
                if tel[i][j] != tel[i - 1][j]:
                    break
                ans += 1
        print(ans)
    except EOFError:
        break
