# bee 1222 - Concurso de Contos
# Alonso Martins
# 02/05/2024
while True:
    try:
        N, L, C = map(int, input().split())
        caracteres, linhas, paginas = 0, 1, 1
        conto = input().split()
        
        for palavra in conto:
            size = len(palavra)
            caracteres += size + 1
            
            if caracteres - 1 > C:
                caracteres = size + 1
                linhas += 1

            if linhas > L:
                linhas = 1
                paginas += 1
                
        print(paginas)

    except EOFError:
        break
