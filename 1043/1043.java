// bee 1043 - Triangulo
// Alonso Martins
// 12/04/2023
import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner leia=new Scanner(System.in);
        double a = leia.nextDouble();
        double b = leia.nextDouble();
        double c = leia.nextDouble();
        if(a+b>c && a+c>b && b+c>a) {
            System.out.printf("Perimetro = %.1f\n", a+b+c);
        } else {
            System.out.printf("Area = %.1f\n", ((a+b)*c)/2.0);
        }
    }
}
