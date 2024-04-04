// bee 1018 - Cedulas
// Alonso Martins
// 27/09/2023
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] valoresNotas = {100, 50, 20, 10, 5, 2, 1};
        int[] notasUsadas = new int[7];
        int valor = in.nextInt();
        System.out.println(valor);
        for(int i = 0; i < valoresNotas.length; i ++) {
            notasUsadas[i] = valor/valoresNotas[i];
            valor %= valoresNotas[i];
        }
        for(int i = 0; i < notasUsadas.length; i ++) {
            System.out.printf("%d nota(s) de R$ %d,00\n", notasUsadas[i], valoresNotas[i]);
        }
    }
}
