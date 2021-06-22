#include <stdio.h>


double binpower(double a, int b);
int main(void)
{
    double x, r;
    int t;

    scanf("%lf", &x);
    scanf("%d", &t);
    scanf("%lf", &r);

    if (r == 0)
    {
        printf("%d\n", (int)(x * t));
        return 0;
    }

    r /= (12 * 100);

    double cal = binpower(r + 1, t);
    int result = (x * ((cal - 1) / (r * cal)) + 0.5);

    printf("%d\n", result);
}


double binpower(double a, int b)
{
    double res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = res * a;

        a = a * a;
        b >>= 1;
    }

    return res;
}