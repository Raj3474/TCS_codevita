#include <stdio.h>

int is_happy(int n);
int is_prime(int n);
int main(void)
{
    int l, u, m;

    int tmp = scanf("%d %d %d", &l, &u, &m);
    if (tmp < 3 || l <= 0 || u <= 0 || m <= 0)
    {
        printf("Invalid Input\n");
        return 1;
    }

    int count = 0;
    for (int i = l; i <= u; i++)
    {
        if (is_prime(i) && is_happy(i))
        {
            count++;
            if (count == m)
            {
                printf("%d\n", i);
                return 0;
            }
        }


    }

    printf("No number is present at this index\n");
}


int is_happy(int n)
{
    int sum = 0, rem;

    while (1)
    {
        while (n > 0)
        {
            rem = n % 10;
            n /= 10;
            sum += rem * rem;
        }

        if (sum == 1)
            return 1;
        else if (sum == 4)
            return 0;

        n = sum;
        sum = 0;
    }

}

int is_prime(int n)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

/*
Input1: 1 30 3
output: 19

Input2: 12 33 5
output: No number is present at this index

Input3:	-5 @ 4
output: Invalid Input
*/