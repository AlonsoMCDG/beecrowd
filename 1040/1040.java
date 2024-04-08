// bee 1040 - Media 3
// Alonso Martins
// 12/04/2023
import java.util.Scanner; 
public class Main{
    public static void main(String[] args){
        Scanner leia=new Scanner(System.in);
        double notas=0.0;
        double media=0.0;
        int peso=2;
        
        for(int i = 0; i < 4; i++){
            notas+=leia.nextDouble() * peso;
            peso++;
            if(peso==5) peso=1;
        } 
        media = ((int)notas)/10.0;
        System.out.printf("Media: %.1f\n", media);
        
        if(media>=7){ 
            System.out.println("Aluno aprovado.");
        }else if(media<5) {
            System.out.println("Aluno reprovado.");
        }else{ 
            System.out.println("Aluno em exame.");
            double exame=leia.nextDouble(); 
            System.out.printf("Nota do exame: %.1f\n",exame);
            media=(media+exame)/2.0;
            if(media>=5.0){ 
                System.out.println("Aluno aprovado.");
            }else{
                System.out.println("Aluno reprovado.");
            }
            System.out.printf("Media final: %.1f\n",media);
        }
    }
}
