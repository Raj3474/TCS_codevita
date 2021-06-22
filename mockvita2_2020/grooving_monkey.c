#include <stdio.h>
#include <string.h>


int lcm(int arr[], int n);
int gcd(int a, int b);

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int monkey[n];
        int bool_arr[n], t_arr[n], len = 0;

        memset(bool_arr, 0, n * sizeof(int));

        for (int i = 0; i < n; i++)
            scanf("%d", &monkey[i]);


        int time = 0, x;
        for (int i = 0; i < n; i++)
        {
            time = 0;
            if (bool_arr[i] == 0)
            {
                bool_arr[i] = 1;
                x = i;

                do
                {
                    time++;
                    x = monkey[x] - 1;
                    bool_arr[x] = 1;

                }
                while (x!= i);

                if (time != 1)
                {
                    t_arr[len] = time;
                    len++;
                }
            }
        }

        int result = lcm(t_arr, len);
        printf("result: %d\n", result);
    }
}

int lcm(int arr[], int n)
{
    int ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        ans = ((arr[i] * ans) / gcd(arr[i], ans));
    }

    return ans;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
