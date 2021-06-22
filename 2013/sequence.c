#include <stdio.h>


int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int prev_count, cur_count, prev_L, cur_L, prev_R, cur_R;

    cur_count = 1;
    prev_count = 0;
    prev_L = prev_R = cur_L = cur_R = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            if (cur_count > prev_count)
            {
                prev_L = cur_L;
                prev_R = cur_R;
                prev_count = cur_count;
            }

            cur_L = cur_R = i;
            cur_count =  1;
        }
        else
        {
            cur_R = i;
            cur_count++;
        }
    }

    if (cur_count > prev_count)
    {
        prev_L = cur_L;
        prev_R = cur_R;
    }
    //printf("%d, %d\n", prev_L, prev_R);

    for (int i = prev_L; i <= prev_R; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}