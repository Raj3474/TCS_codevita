#include <stdio.h>

void tri(int n, int b);
void stand(int n);
int main(void)
{
    int N;
    scanf("%d", &N);

    if (N <= 1)
    {
        printf("You cannot generate christmas tree\n");
        return 1;
    }

    if (N > 20)
    {
        printf("Tree is no more\n");
        return 1;
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (i == N - 2 && N > 3)
        {
            tri(N, N - i);
        }
        else
            tri(N, i);

    }

    stand(N);
}


void tri(int n, int b)
{
    for (int i = 0; i < n - b; i++)
    {
        // for the top
        if ((b == 0 && i == 0))
        {
            for (int j = 0; j < n - i; j++)
                printf(" ");
            printf("*\n");
        }



        for (int j = 0; j < n - i - 1; j++)
                printf(" ");
        for (int k = 0; k <= 2 * (i + 1); k++)
            printf("*");

        printf("\n");
    }

}

void stand(int n)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" ");
        printf("*\n");
    }
}