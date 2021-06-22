#include <stdio.h>
#include <math.h>

int pascal[21][21];

void cal_pascals();
int gcd(int a, int b);

int main(void)
{
    int t;
    scanf("%d", &t);

    cal_pascals();
    while (t--)
    {
        int A, Heal, L1, L2, M, C;

        scanf("%d %d %d %d %d %d", &A, &Heal, &L1, &L2, &M, &C);

        if (Heal > M * (A + C))
        {
            printf("RIP\n");
            return 0;
        }
        else if (Heal <= M * A)
        {
            printf("1/1\n");
            return 0;
        }

        int tmp = Heal - M * A, s = 0;

        while (tmp > 0)
        {
            s++;
            tmp -= C;
        }

        int num =  0, den = 0;
        for (int i = s; i <= M; i++)
        {
            num += pascal[M][i] * (pow(L1, i) * pow(L2 - L1, M - i));
        }

        den = pow(L2, M);

        int common_factor = gcd(num, den);
        num /= common_factor;
        den /= common_factor;
        printf("%d/%d\n", num, den);

    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void cal_pascals()
{
    for (int i = 0; i <= 20; i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
    }

    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j < i; j++)
        {

            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];

        }
    }

    // for (int i = 0; i <= 20; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         printf("%d ", pascal[i][j]);
    //     }
    //     printf("\n");
    // }
}