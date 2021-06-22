#include <stdio.h>


int find_num_factors(int x);
int main(void)
{
    int n, sum1 = 0, sum2 = 0;
    scanf("%d", &n);

    if (n == 1)
    {
        printf("AMAN\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        if (x == 1)
            continue;

        sum2 ^= x;
        printf("num factors: %d\n", find_num_factors(x));
        sum1 += find_num_factors(x);
    }

    if (sum1 % 2 == 0)
        printf("JASBIR\n");
    else
        printf("AMAN\n");

    if (sum2 % 2 == 0)
        printf("JASBIR\n");
    else
        printf("AMAN\n");
}


int find_num_factors(int x)
{
    int num = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int a = x / i;
            if (a != i)
                num += 2;
            else
                num++;
        }
    }
    return num;
}