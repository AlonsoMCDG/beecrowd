// bee 3303 - Palavrao
// Alonso Martins
// 20/02/2024
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println(s.length() >= 10 ? "palavrao" : "palavrinha");
    }
}
