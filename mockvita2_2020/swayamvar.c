#include <stdio.h>


int main(void)
{
    int n;
    scanf("%d", &n);

    char b[n], g[n];
    int rb[n], mb[n], rg[n], mg[n];


    for (int i = 0; i < n; i++)
    {
        char tmp = getchar();
        scanf("%c", &b[i]);
    }

    for (int i = 0; i < n; i++)
    {
        char tmp = getchar();
        scanf("%c", &g[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%c,%c\n", b[i], g[i]);
    // }

    int Rb = 0, Mb = 0, Rg = 0, Mg = 0, result = 0;

    for (int i = 0; i < n; i++)
    {
        if (b[i] == 'r')
            Rb++;
        else
            Mb++;

        if (g[i] == 'r')
            Rg++;
        else
            Mg++;

        rb[i] = Rb, mb[i] = Mb;
        rg[i] = Rg, mg[i] = Mg;
    }

    // for (int i = 0; i < n; i++)
    //     printf("%d ", rb[i]);
    // printf("\n");

    // for (int i = 0; i < n; i++)
    //     printf("%d ", mb[i]);
    // printf("\n");

    // for (int i = 0; i < n; i++)
    //     printf("%d ", rg[i]);
    // printf("\n");

    // for (int i = 0; i < n; i++)
    //     printf("%d ", mg[i]);
    // printf("\n");


    if (rg[n - 1] <= mg[n - 1])
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (rb[i] == rg[n - 1])
            {
                result = n - rb[i] - mb[i];
                break;
            }
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (mb[i] == mg[n - 1])
            {
                result = n - rb[i] - mb[i];
                break;
            }
        }
    }

    printf("Result: %d\n", result);
}