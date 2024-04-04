// bee 3342 - Keanu
// Alonso Martins
// 20/02/2024
import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), pretas, brancas;
    
        pretas = (n * n) / 2;
        brancas = pretas + (n % 2);
        System.out.println(brancas+" casas brancas e "+pretas+" casas pretas");
	}
}
