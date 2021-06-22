#include <stdio.h>



int main(void)
{
    int test;
    scanf("%d", &test);

    while (test--)
    {
        int F, B, T, FD, BD, result, dist, n = 0;
        scanf("%d %d %d %d %d", &F, &B, &T, &FD, &BD);

        if (F >= FD)
        {
            result = FD * T;
            printf("result: %d F\n", result);
        }
        else if (F == B)
        {
            printf("No Ditch\n");
        }
        else
        {
            // first method
            if (F > B)
            {
                n = (FD - F) / (F - B);

                if ((FD - F) % (F - B) == 0)
                    result = (n * F + n * B + F) * T;
                else
                    result = ((n + 1) * (F + B) + (FD - (n + 1) * (F - B))) * T;
                printf("result: %d F\n", result);
            }

            if (B > F)
            {
                n = BD / (B - F);

                if (BD % (B - F) == 0)
                    result = (n * B + n * F) * T;
                else
                    result = ((n + 1) * (B + F) + (BD - (n + 1) * (B - F))) * T;
                    printf("result: %d B\n", result);
            }

            //Alternative method
            /*while (1)
            {
                n++;
                dist = n * F - (n - 1) * B;
                if (dist >= FD)
                    break;

                dist = n * F - n * B;
                if (dist <= -1 * BD)
                    break;
            }

            if (dist > 0)
            {
                result = (n * F + (n - 1) * B) * T - (dist - FD) * T;
                printf("result: %d F\n", result);
            }
            else
            {
                result = (n * F + n * B) * T - (-1*dist - BD) * T;
                printf("result: %d B\n", result);
            }
            */
        }
    }
}