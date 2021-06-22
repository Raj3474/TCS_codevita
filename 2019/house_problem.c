#include <stdio.h>


#define fi(a, b) for (int i = a; i < b; i++)
#define fie(a, b) for (int i = a; i <= b; i++)

int max(int a, int b)
{
    return (a > b ? a : b);
}

int main(void)
{
    int hval[] = {6, 8, 1, 3, 8, 2, 5};
    int n = 7;

    int dp[n];

    dp[0] = hval[0];
    dp[1] = hval[1];
    dp[2] = hval[0] + hval[2];

    fi(3, n)
    {
        dp[i] = hval[i] + max(dp[i - 2], dp[i - 3]);
    }

    printf("%d\n", max(dp[n - 1], dp[n - 2]));
}

/*
Test cases:-

input: 6, 8, 1, 3, 8, 2, 5
output:21

input: 6, 7, 1, 3, 8, 2, 5
output = 20

*/