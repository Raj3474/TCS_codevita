#include <stdio.h>
#include <string.h>


int even_count(int set[], int lim);
int find(int set[], int x);
int main(void)
{
    int n;
    scanf("%d", &n);

    int set[n + 1];
    memset(set, -1, sizeof(set));

    while (1)
    {
        char tmp, query;

        tmp = getchar();
        scanf("%c", &query);


        if (query == 'C')
        {
            int x, y;
            scanf("%d%d", &x, &y);

            x = find(set, x);
            y = find(set, y);

            //printf("a: %d, b: %d\n", a, b);
            if (x != y)
            {
                if (-set[x] < -set[y])
                {
                    set[y] += set[x];
                    set[x] = y;
                }
                else
                {
                    set[x] += set[y];
                    set[y] = x;
                }
            }
        }
        else if (query == 'Q')
        {
            int x, y;
            scanf("%d%d", &x, &y);

            printf("%d\n", even_count(set, n));
        }
        else
        {
            break;
        }
    }
}

int find(int set[], int x)
{
    if (set[x] < 0)
        return x;

    set[x] = find(set, set[x]);

    return set[x];
}

int even_count(int set[], int lim)
{
    int count = 0;

    for (int i = 1; i <= lim; i++)
    {
        if (set[i] < 0 && set[i] % 2 == 0)
        {
            count++;
        }
    }

    return count;
}