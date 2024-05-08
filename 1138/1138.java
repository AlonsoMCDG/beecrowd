// bee 1138 - Contagem de Digitos
// Alonso Martins
// 07/05/2024
import java.util.Scanner;

public class Main {
    public static void contarDigitos(int[] v, int n) {
        if (n == 0) 
            return;
        
        int t1, t2, t3, dig;
        int contador;
        
        // unidades
        for (int i = 1; i < 10; i ++)
            v[i] += n / 10 + (n % 10 >= i ? 1 : 0);
        
        v[0] = n / 10; // o zero conta diferente
        
        // resto das casas
        for (int i = 1; i <= 8; i ++) {
            t1 = (int)Math.pow(10, i);
            t2 = n / (int)Math.pow(10, i + 1);
            t3 = n % t1 + 1;
            dig = (n / t1) % 10;
            
            v[0] += (t2 > 1 ? (t2 - 1) * t1 : 0) + (t2 != 0 && dig != 0 ? t1 : 0) + (t2 != 0 && dig == 0 ? t3 : 0); // o zero conta diferente
            
            for (int d = 1; d < 10; d ++) { // conta os dígitos de 1 a 9 na posicao 10^i
                contador = (t2 + (dig > d ? 1 : 0)) * t1 + t3 * (dig == d ? 1 : 0);
                v[d] += contador;
            }
            
            if (t2 == 0)
                break;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int A, B;
        
        while ((A = in.nextInt()) > 0 && (B = in.nextInt()) > 0) {
            int[] left_bound = new int[10], right_bound = new int[10];
            
            contarDigitos(left_bound, A - 1);
            contarDigitos(right_bound, B);
            
            for (int i = 0; i < 10; i ++)
                System.out.printf("%d%s", right_bound[i] - left_bound[i], i == 9 ? "\n" : " ");
        }
    }
}
