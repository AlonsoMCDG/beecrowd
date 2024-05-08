// bee 1138 - Contagem de Digitos
// Alonso Martins
// 08/05/2024
using System;

class URI
{

    static void contar_digitos(int[] v, int n)
    {
        if (n <= 0)
            return;

        int t1, t2, t3, dig;
        int i, d, contador;

        // unidades
        for (i = 1; i < 10; i ++)
            v[i] += n / 10 + (n % 10 >= i ? 1 : 0);

        v[0] = n / 10; // o zero conta diferente

        // resto das casas
        for (i = 1; i <= 8; i ++)
        {
            t1 = (int)Math.Pow(10, i);
            t2 = n / (int)(Math.Pow(10, i + 1));
            t3 = n % t1 + 1;
            dig = (n / t1) % 10;

            v[0] += (t2 > 1 ? 1 : 0) * (t2 - 1) * t1 + (t2 > 0 && dig != 0 ? 1 : 0) * t1 + (t2 > 0 && dig == 0 ? 1 : 0) * t3; // o zero conta diferente

            for (d = 1; d < 10; d ++)   // conta os dígitos de 1 a 9 na posicao 10^i
            {
                contador = (t2 + (dig > d ? 1 : 0)) * t1 + t3 * (dig == d ? 1 : 0);
                v[d] += contador;
            }

            if (t2 == 0)
                break;
        }
    }
    static void Main(string[] args)
    {
        int A, B, i;

        while (true)
        {
            string[] input = Console.ReadLine().Split(' ');

            A = int.Parse(input[0]);
            B = int.Parse(input[1]);

            if (A <= 0 || B <= 0)
                break;

            int[] left_bound = new int[10], right_bound = new int[10];

            contar_digitos(left_bound, A - 1);
            contar_digitos(right_bound, B);

            for (i = 0; i < 10; i ++)
                Console.Write($"{right_bound[i] - left_bound[i]}{(i == 9 ? "\n" : " ")}");
        }
    }

}
