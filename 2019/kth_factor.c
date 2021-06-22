#include <stdio.h>


int main(void)
{

    long long N;
    int k;
    scanf("%lld%d", &N, &k);

    int c = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            printf("%d ", i);
            c++;
        }


        if (c == k)
        {
            printf("\n%d-th factor: %d\n", c, i);
            return 0;
        }
    }


    if (k > c)
    {
        printf("1\n");
    }
}