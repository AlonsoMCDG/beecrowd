// bee 1037 - Intervalo
// Alonso Martins
// 12/04/2023
import java.util.Scanner; 
public class Main {
    public static void main(String[] args) {
        Scanner leia= new Scanner(System.in);
        double v = leia.nextDouble();
        if(v>=0.0 && v<=25.0) {
            System.out.println("Intervalo [0,25]");
        } else if(v>25.0 && v<=50.0) {
            System.out.println("Intervalo (25,50]");
        } else if(v>50.0 && v<=75.0) {
            System.out.println("Intervalo (50,75]");
        } else if(v>75.0 && v<=100.0) {
            System.out.println("Intervalo (75,100]");
        } else {
            System.out.println("Fora de intervalo");
        }
    }
}
