#include <stdio.h>


int main(void)
{
    int N;
    scanf("%d", &N);

    int dp[N/2];
    int size = 0;

    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            dp[size] = i;
            size++;

            if (i != N/i)
            {
                dp[size] = N / i;
                size++;
            }
        }
    }

    if (N > 1)
    {
        dp[size] = N;
        size++;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", dp[i]);
    printf("\n");

    int num_not_square_free = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 2; j * j <= dp[i]; j++)
        {
            if (dp[i] % (j * j) == 0)
            {
                printf("num: %d\n", dp[i]);
                num_not_square_free++;
                break;
            }

        }
    }

    int result = size - num_not_square_free;

    printf("%d\n", result);
}