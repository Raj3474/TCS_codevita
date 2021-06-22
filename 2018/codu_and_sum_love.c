#include <stdio.h>


int binpower(int a, int b, int m);
int main(void)
{
    int n;
    scanf("%d", &n);

    int sum = 0, m = 100;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        sum += binpower(2, x, m);
    }

    printf("%d\n", sum % m);
}


int binpower(int a, int b, int m)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;

        a = (a * a) % m;

        b >>= 1;
    }

    return res;
}