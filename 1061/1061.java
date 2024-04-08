// bee 1061 - Tempo de um Evento
// Alonso Martins
// 13/04/2023
import java.util.Scanner; 
public class Main{
    public static void main(String[] args){
        Scanner leia=new Scanner(System.in);
        leia.next();
        int dia1 = Integer.parseInt(leia.next());
        int hora1 = Integer.parseInt(leia.next());
        leia.next();
        int minuto1 = Integer.parseInt(leia.next());
        leia.next();
        int segundo1 = Integer.parseInt(leia.next());
        leia.next();
        int dia2 = Integer.parseInt(leia.next());

        int hora2 = Integer.parseInt(leia.next());
        leia.next();
        int minuto2 = Integer.parseInt(leia.next());
        leia.next();
        int segundo2 = Integer.parseInt(leia.next());
        
        int tempo = (dia2*86400 + hora2*3600 + minuto2*60 + segundo2) - 
                    (dia1*86400 + hora1*3600 + minuto1*60 + segundo1);
        
        int dias = tempo/86400;
        tempo%=86400;
        int horas = tempo/3600;
        tempo%=3600;
        int minutos = tempo/60;
        tempo%=60;
        int segundos = tempo;
        
        System.out.println(dias+" dia(s)");
        System.out.println(horas+" hora(s)");
        System.out.println(minutos+" minuto(s)");
        System.out.println(segundos+" segundo(s)");
    }
}
