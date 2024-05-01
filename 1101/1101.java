// bee 1101 - Sequencia de Numeros e Soma
// Alonso Martins
// 29/01/2023
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int M, N;
        do {
            M = in.nextInt();
            N = in.nextInt();
            if(M <= 0 || N <= 0) break;
            if(M > N) {
                int t = M; M = N; N = t;
            }
            for (int i = M; i <= N; i ++) {
                System.out.print(i+" ");
            }
            System.out.println("Sum="+((M+N)*(N-M+1)/2));
        } while(M > 0 && N > 0);
    }
}
