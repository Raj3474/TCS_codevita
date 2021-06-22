#include <stdio.h>
#include <string.h>


int cal_val(int s, int digit[]);
int main (void)
{
    int digit[10], x;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    memset(digit, 0, 10 * sizeof(int));

    while (1)
    {
        scanf("%d", &x);
        char tmp = getchar();

        digit[x]++;

        if (tmp == '\n')
            break;
    }

    // for (int i = 0; i < 10; i++)
    //     printf("%d ", digit[i]);
    // printf("\n");

    int mon = cal_val(12, digit);
    if (mon == -1)
    {
        printf("0\n");
        return 0;
    }

    int d = cal_val(days[mon-1], digit);
    if (d == -1)
    {
        printf("0\n");
        return 0;
    }

    int h = cal_val(23, digit);
    if (h == -1)
    {
        printf("0\n");
        return 0;
    }

    int min = cal_val(59, digit);
    if (min == -1)
    {
        printf("0\n");
        return 0;
    }

    printf("%d/%d %d:%d\n", mon, d, h, min);
}

int cal_val(int s, int digit[])
{
    int a, b;
    for (int i = s; i > 0; i--)
    {
        a = i / 10, b = i % 10;

        //printf("a:%d-%d, b:%d-%d\n", a, digit[a], b, digit[b]);
        if (digit[a] && digit[b])
        {
            digit[a]--, digit[b]--;
            return i;
        }
    }

    return -1;
}