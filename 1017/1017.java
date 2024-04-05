// bee 1017 - Gasto de Combustivel
// Alonso Martins
// 27/09/2023
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tempo = in.nextInt(), velocidade = in.nextInt();
        int distancia = velocidade * tempo;
        double litros = distancia/12.0;
        System.out.printf("%.3f\n", litros);
    }
}
