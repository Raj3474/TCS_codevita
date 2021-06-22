#include <stdio.h>
#include <string.h>


int arr[10001];


int fun(int n);
int main(void)
{
    memset(arr, -1, 10001 * (sizeof(int)));
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 0;
    arr[4] = 0;

    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);


        // method 1
        int result = fun1(N);
        if (result == 0)
            printf("YES\n");
        else if (result == 1)
            printf("NO\n");


        // alternative method from the pattern observe
        if (N % 5 == 0 || N % 5 == 2)
            printf("NO\n");
        else
            printf("Yes\n");
    }
}

int fun1(int n)
{
    if (n <= 4)
        return arr[n];

    if (arr[n] == -1)
    {
        int a = fun(n - 1), b = fun(n - 4);

        arr[n] = !(a | b);
    }

    return arr[n];
}