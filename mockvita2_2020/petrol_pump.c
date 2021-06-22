#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int n = 0, s = 0;

    int a[50];

    char tmp;
    do
    {
        scanf("%d%c", &a[n], &tmp);
        s += a[n];
        n++;
    }
    while (tmp != '\n');

    int dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= a[i - 1])
            {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i - 1]];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    int an = s;
    for (int i = s/2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            an = s - i;
            break;
        }
    }

    printf("%d\n", an);
}

/*
Input 1: 1 2 3 4 5 10 11 3 6 16
output: 31

Input 2: 25 30 35 20 90 110 45 70 80 12 30 35 85
output: 335
*/