#include <stdio.h>


int main(void)
{
    int N, num_one = 1, num_two, num_five;
    scanf("%d", &N);

    num_five = (N - 4) / 5;

    if ((N - 5 * num_five) % 2 == 0)
        num_one = 2;

    num_two = (N - 5 * num_five - num_one) / 2;

    printf("%d %d %d %d\n", (num_one + num_two + num_five), num_five, num_two, num_one);
}