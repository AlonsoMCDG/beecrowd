// bee 1222 - Concurso de Contos
// Alonso Martins
// 02/05/2024
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int N, L, C;
        int caracteres, linhas, paginas, len;
        String palavra = new String();

        while (in.hasNext()) {
            N = in.nextInt(); L = in.nextInt(); C = in.nextInt();
            caracteres = 0; linhas = paginas = 1;

            for (int i = 0; i < N; i ++) {
                palavra = in.next(); len = palavra.length();
                caracteres += len + 1;

                if (caracteres - 1 > C)
                {
                    caracteres = len + 1;
                    linhas ++;
                }
                if (linhas > L)
                {
                    linhas = 1;
                    paginas ++;
                }
            }

            System.out.println(paginas);
        }

        in.close();
    }
}
