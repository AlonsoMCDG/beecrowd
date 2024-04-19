// bee 1020 - Idade em Dias
// Alonso Martins
// 18/04/2024
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a, m, d = scanner.nextInt();
        
        a = d / 365;
        d %= 365;
        m = d / 30;
        d %= 30;

        System.out.println(a + " ano(s)");
        System.out.println(m + " mes(es)");
        System.out.println(d + " dia(s)");
        
        scanner.close();
    }
}
