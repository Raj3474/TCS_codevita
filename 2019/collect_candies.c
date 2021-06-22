#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);

        int sum = 0;
        int x;
        scanf("%d", &x);

        sum += x * (N - 1);

        for (int i = 1; i < N; i++)
        {
            scanf("%d", &x);
            sum += x * (N - i);
        }

        printf("%d\n", sum);
    }
}

