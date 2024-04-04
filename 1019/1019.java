// bee 1019 - Conversao de Tempo
// Alonso Martins
// 27/09/2024
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tempo = in.nextInt();
        int hh = tempo/3600;
        tempo %= 3600;
        int mm = tempo/60;
        tempo %= 60;
        int ss = tempo;
        System.out.printf("%d:%d:%d\n", hh, mm, ss);
    }
}
