// bee 3302 - Resposta Certa
// Alonso Martins
// 20/02/2024
import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        
        for(int i = 0; i < n; i ++) {
            System.out.println("resposta "+(i+1)+": "+in.nextInt());
        }
	}
}
