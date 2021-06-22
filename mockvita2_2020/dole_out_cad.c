#include <stdio.h>


int cal_sq(int , int);
int main(void)
{
    int min_l, max_l, min_b, max_b, result = 0;

    scanf("%d %d", &min_l, &max_l);
    scanf("%d %d", &min_b, &max_b);

    for (int i = min_l; i <= max_l; i++)
    {
        for (int j = min_b; j <= max_b; j++)
        {
            int num_squares = cal_sq(i, j);
            result += num_squares;
            printf("num of squares: %d, for %dx%d\n", num_squares, i, j);
        }
    }
    printf("Total number of squres: %d\n", result);
}

int cal_sq(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    if (a == 1)
        return b;

    if (b == 1)
        return a;

    if (a == b)
        return 1;

    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;

    return (max / min) + cal_sq(max % min, min);
}