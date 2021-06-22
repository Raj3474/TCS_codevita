#include <stdio.h>


int main(void)
{
     int N;
     scanf("%d", &N);

     int a = 2, b = 3, res = a * b;
     for (int i = 0; i < N; i++)
     {
         // print blank spaces
         for (int j = 0; j < N - i - 1; j++)
         {
             printf("   ");
         }

         for (int k = 0; k < i; k++)
         {
             printf("%.5d ", res);
             a += 2, b += 4;
             res = a*b;
         }
         printf("\n");
     }
}