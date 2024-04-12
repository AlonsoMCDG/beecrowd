// bee 1118 - Varias Notas com Validacao
// Alonso Martins
// 29/01/2023
import java.io.IOException;
import java.util.Scanner;

public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        double n1, n2;
        int X = 0;
        do {
            n1 = in.nextDouble();
            while(n1 < 0 || n1 > 10) {
                System.out.println("nota invalida");
                n1 = in.nextDouble();
            }
            n2 = in.nextDouble();
            while(n2 < 0 || n2 > 10) {
                System.out.println("nota invalida");
                n2 = in.nextDouble();
            }
            System.out.print("media = "+(n1+n2)/2.0); 
            System.out.println((((n1+n2)/2.0)+"").length() == 3 ? "0" : "");
            do {
                System.out.println("novo calculo (1-sim 2-nao)");
                X = in.nextInt();
            } while(X < 1 || X > 2);
        }while(X == 1);
    }
 
}
