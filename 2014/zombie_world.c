#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int k;
    scanf("%d", &k);

    while (k--)
    {
        int N, T;
        scanf("%d %d", &N, &T);

        if (N > T)
        {
            printf("NO\n");
            return 0;
        }

        int E[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &E[i]);
        }

        qsort(E, N, sizeof(int), compare);
        int P, D;
        scanf("%d %d", &P, &D);


        for (int i = 0; i < N; i++)
        {
            printf("%d %d\n", E[i], P);

            if (E[i] > P)
            {
                printf("NO\n");
                return 0;
            }

            P += P - E[i];
        }

        if (P >= D)
            printf("YES\n");
    }
}