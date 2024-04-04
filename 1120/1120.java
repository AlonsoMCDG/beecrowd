// bee 1120 - Revisao de Contrato
// Alonso Martins
// 13/12/2023
import java.util.Scanner;

public class Main
{
	static String D;        // digito com falha
	static String N;        // valor numerico digitado no contrato
	
	static boolean entradaCorreta(String d, String n) { // função que retorna falso se a entrada é 0 0
	    D = d; 
	    N = n;
	    return D.compareTo("0") != 0 || N .compareTo("0") != 0;
	}
	
	static int countMatches(String s, char t) { // função para contar quantas vezes char t aparece na String s
	    int count = 0;
	    for(int i = 0; i < s.length(); i ++) 
	        if (t == s.charAt(i)) count ++;
	    return count;
	}
	
	static String encontrarValorNoContrato() {  // calcula qual valor está no contrato
	    N = N.replace(D, "");           // remove os digitos com falha
	    if(N.length() == 0) return "0"; // todos os dígitos eram falhos
	    
	    // remove os zeros à esquerda
	    char[] n = N.toCharArray();
	    int i = 0;
	    while(n[i] == '0' && i+1 < n.length) i ++;
	    if(i == n.length) return "0";
	    return N.substring(i, N.length());
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (entradaCorreta(in.next(), in.nextLine().trim())) {
		    N = encontrarValorNoContrato(); 
		    System.out.println(N); // imprime o valor final no contrato
		}
	}
}
