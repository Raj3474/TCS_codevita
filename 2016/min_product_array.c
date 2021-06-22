#include <stdio.h>
#include <stdlib.h>

#define fi(a,b) for (int i = a; i < b; i++)


int main(void)
{
    int n, k;

    scanf("%d %d", &n, &k);
    int A[n], B[n];

    fi(0, n)
        scanf("%d", &A[i]);

    fi(0, n)
        scanf("%d", &B[i]);

    int max = B[0], x, sum = 0;
    fi(0, n)
    {
        sum += A[i] * B[i];

        if (abs(B[i])  > max)
        {
            max = B[i];
            x = i;
        }
    }

    int tmp = (B[x] < 0 ? +1: -1);

    sum = sum + tmp * k * 2 * B[x];
    printf("result: %d\n", sum);
}