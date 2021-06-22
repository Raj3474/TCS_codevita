#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int  N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int X;
    scanf("%d", &X);

    qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);


    for (int i = 0; i < N - 2; i++)
    {
        int sum = arr[i];

        if (sum >= X)
        {
            break;
        }


        for (int j = i + 1; j < N - 1; j++)
        {
            sum += arr[j];

            if (sum >= X)
            {
                sum -= arr[j];
                break;
            }

            for (int k = j + 1; k < N; k++)
            {
                sum += arr[k];

                if (sum > X)
                {
                    sum -= arr[k];
                    break;
                }

                if (sum == X)
                {
                    printf("True\n");
                    return 0;
                }
                sum -= arr[k];
            }
            sum -= arr[j];
        }
    }

    printf("False\n");
}

/*
Test cases:-

input 1:

6
1
4
45
6
10
8
22

output 1:
True


input 2:
4
1
3
12
4
14

output 2:
False
*/