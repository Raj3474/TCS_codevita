#include <stdio.h>


#define M 20
#define N 20

char forest[M][N];
int path[M][N];

int m, n;

void find(int i, int j, int t);
int main(void)
{

    scanf("%d %d", &m, &n);

    int x, y;
    scanf("%d %d\n", &x, &y);

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            scanf("%c", &forest[i][j]);
            char buffer = getchar();
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = 10000;
        }
    }

    find(x - 1, y - 1, 1);


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d \t", path[i][j]);
        }
        printf("\n");
    }

    int min = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (path[i][j] != 10000 && path[i][j] > min)
                min = path[i][j];
        }
    }

    printf("total time: %d\n", min);
}



void find(int i, int j, int t)
{
    path[i][j] = t;

    // all diagonal directions first
    if (i - 1 >= 0 && j - 1 >= 0 && forest[i - 1][j - 1] != 'W' && path[i - 1][j - 1] > t + 1)
        find(i - 1, j - 1, t + 1);

    if (i - 1 >= 0 && j + 1 < n && forest[i - 1][j + 1] != 'W' && path[i - 1][j + 1] > t + 1)
        find(i - 1, j + 1, t + 1);

    if (i + 1 < m && j - 1 >= 0 && forest[i + 1][j - 1] != 'W' && path[i + 1][j - 1] > t + 1)
        find(i + 1, j - 1, t + 1);

    if (i + 1 < m && j + 1 < n && forest[i + 1][j + 1] != 'W' && path[i + 1][j + 1] > t + 1)
        find(i + 1, j + 1, t + 1);


    // all lateral directions
    if (i - 1 >= 0 && forest[i - 1][j] != 'W' && path[i - 1][j] > t + 1)
        find(i - 1, j, t + 1);

    if (i + 1 < m && forest[i + 1][j] != 'W' && path[i + 1][j] > t + 1)
        find(i + 1, j, t + 1);

    if (j - 1 >= 0 && forest[i][j - 1] != 'W' && path[i][j - 1] > t + 1)
        find(i, j - 1, t + 1);

    if (j + 1 < n && forest[i][j + 1] != 'W' && path[i][j + 1] > t + 1)
        find(i, j + 1, t + 1);
}

/*
Test cases:-

input 1:-
3 3
1 3
W T T
T W W
W T T

output 1:-
5


input 2:-
6 6
1 6
W T T T T T
T W W W W W
W T T T T T
W W W W W T
T T T T T W
T W W W W W

output 2:-
16
*/