// bee 1002 - Area do Circulo
// Alonso Martins
// 27/09/2023
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double r = in.nextDouble();
        System.out.printf("A=%.4f\n", (r*r*3.14159));
    }
}
