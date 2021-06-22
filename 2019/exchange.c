#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stra[10];
char strb[10];
int b;

char com[10];
int c[10];

int compare(const void *x, const void *y)
{
    return (*(char *)x - *(char *)y);
}

void permu(int lena, int ia);
int main(void)
{
    memset(c, 0, 10 * sizeof(int));
    scanf("%s %s", stra, strb);

    int lena = strlen(stra);

    qsort(stra, lena, sizeof(char), compare);
    int ia = 0, ib = 0;

    for (int i = 0; i < lena; i++)
    {
        if (stra[i] >= strb[ia])
        {
            com[ia] = stra[i];
            c[i] = 1;
            permu(lena, ia + 1);
            c[i] = 0;
        }
    }
    printf("-1\n");
}


void permu(int lena, int ia)
{
    if (ia == lena)
    {
        com[ia] = '\0';
        printf("%s\n", com);
        if (atoi(com) > atoi(strb))
        {
            printf("%s\n", com);
            exit(0);
        }

        return;
    }

    for (int i = 0; i < lena; i++)
    {
        if (c[i])
            continue;


        com[ia] = stra[i];
        c[i] = 1;
        permu(lena, ia + 1);
        c[i] = 0;
    }
}