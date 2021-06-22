#include <stdio.h>
#include <string.h>


int main(void)
{
    int n;
    scanf("%d", &n);

    int odd_arr[10], even_arr[10];

    memset(odd_arr, 0, 10 * sizeof(int));
    memset(even_arr, 0, 10 * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int num, digit, max = 0, min = 9;
        scanf("%d", &num);

        for (int j = 0; j < 3; j++)
        {
            digit = num % 10;
            num /= 10;

            if (digit > max)
                max = digit;

            if (digit < min)
                min = digit;
        }

        num = max * 11 + min * 7;
        num = num % 100;
        num = num / 10;

        if (i % 2 == 0)
        {
            even_arr[num] += 1;
        }
        else
        {
            odd_arr[num] += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", odd_arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", even_arr[i]);
    }
    printf("\n");

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = (odd_arr[i] > even_arr[i]) ? odd_arr[i] : even_arr[i];

        if (x == 2)
            result = result + 1;
        else if (x > 2)
            result = result + 2;
    }

    printf("result: %d\n", result);
}