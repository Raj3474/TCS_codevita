#include <stdio.h>


int main(void)
{
    int test;
    scanf("%d", &test);

    while (test--)
    {
        int F, B, T, D;
        scanf("%d %d %d %d", &F, &B, &T, &D);


        if (D <= B)
        {
            printf("%d\n", D * T);
        }
        else
        {
            int result, n;
            n = (D - B) / (B -  F);

            if ((D - B) % (B -  F) == 0)
                result = (n * (B + F) + B) * T;
            else
                result = ((n + 1) * (B + F) + (D - (n + 1) * (B - F))) * T;

            printf("result: %d\n", result);

        }
    }
}