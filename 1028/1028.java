// bee 1028 - Figurinhas
// Alonso Martins
// 05/04/2023
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for (int i = 0; i < n; i++) {
            int f1 = sc.nextInt();
            int f2 = sc.nextInt();
            int gcd = gcd(f1, f2); //calcula o MDC
            
            System.out.println(gcd);
        }
        
        sc.close();
    }
    
    //Método para calcular o MDC (Máximo Divisor Comum) entre dois números
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        
        return gcd(b, a % b);
    }
}
