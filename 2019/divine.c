#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *) a - *(int *)b);
}


int main(void)
{
    int N;
    scanf("%d", &N);

    int dp[N/2];

    dp[0] = 1;
    int size = 1;

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

    qsort(dp, size, sizeof(int), compare);

    for (int i = 0; i < size; i++)
        printf("%d ", dp[i]);
    printf("\n");
}