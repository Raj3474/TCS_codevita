#include <stdio.h>
#include <math.h>

#define H(n) (n * (2 * n - 1))
#define T(n) ((n * (n + 1))/2)

int get_n(int num);
int main(void)
{
    int l, u, m;

    int tmp = scanf("%d %d %d", &l, &u, &m);
    if (tmp < 3 || l <= 0 || u <= 0 || m <= 0)
    {
        printf("Invalid Input\n");
        return 1;
    }

    // for (int i = 1; i < 10; i++)
    //     printf("i: %d , %d, %d\n", i, H(i), T(i));
    // printf("%d\n", get_n(l));


    int n = get_n(l), count = 0;

    int h = H(n);
    while (h <= u)
    {
        if (h < l)
        {
            n++;
            h = H(n);
            continue;
        }

        //printf("%d\n", h);
        count++;
        if (count == m)
        {
            printf("%d\n", h);
            return 0;
        }

        n++;
        h = H(n);
    }

    printf("No number is present at this index\n");

}

int get_n(int n)
{
    const double eps = 1E-15;

    double x = 1;
    while(1)
    {
        double nx = (2 * x * x + x + n) / (4 * x - 1);
        if (fabs(x - nx) < eps)
            break;
        x = nx;
    }
    return (int) x + .01 - 1;
}

/*
Input:- 90 150 2
Output:- 120

Input:- 20 80 6
Output:- No number is present at this index

Input:- -5 3 a
Output:- Invalid Input
*/