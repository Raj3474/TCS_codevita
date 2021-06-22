#include <stdio.h>


int arr[10000], dp[10000][10000];

int main(void)
{
    int n = 0;
    char tmp;
    do
    {
        int x;

        scanf("%d", &x);
        tmp = getchar();

        arr[n++] = x;
    }
    while (tmp != '\n');

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = arr[i];
            else
                dp[i][j] = dp[i][j - 1] + arr[j];
        }
    }

    // finding the accico equi pairs
    int a, b, pair_found = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i+2; j < n-1; j++)
        {
            if (dp[0][i-1] == dp[i+1][j-1] && dp[i+1][j-1] == dp[j+1][n-1])
            {
                a = i, b = j;
                pair_found = 1;
                break;
            }
        }
    }

    if (pair_found)
    {
        printf("{ %d,%d }\n{ %d,%d }, { %d,%d }, { %d,%d }\n", a, b, 0, a-1, a+1, b-1, b+1, n-1);
    }
    else
    {
        printf("Array does not contain any equi pair\n");
    }
}