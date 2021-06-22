#include <stdio.h>


int find(int x, int arr[], int lim);
int main(void)
{
    int n;
    scanf("%d", &n);

    int set[n], num_ele[n], set_size = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d,", &x);

        int r = find(x, set, set_size);
        if (r == -1)
        {
            set[set_size] = x;
            num_ele[set_size++] = 1;
        }
        else
        {
            num_ele[r]++;
        }
    }

    // for (int i = 0; i < set_size; i++)
    // {
    //     printf("%d, %d\n", set[i], num_ele[i]);
    // }

    int result = 0;
    for (int i = 0; i < set_size; i++)
    {
        result += (num_ele[i] * (num_ele[i] - 1))/2;
    }

    printf("%d\n", (result * (result - 1))/2);

}

int find(int x, int arr[], int lim)
{
    for (int i = 0; i < lim; i++)
    {
        if (arr[i] == x)
            return i;
    }

    return -1;
}