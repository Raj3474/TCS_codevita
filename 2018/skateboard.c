#include <stdio.h>

char matrix[50][50][4];

int check(int a, int b, char c);
int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%s", matrix[i][j]);

    /*for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            printf("%s ", matrix[i][j]);
    */
    int path_matrix[N][N];
    path_matrix[N - 1][N - 1] = 1;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {

            if ((j - 1) >= 0 && path_matrix[i][j - 1] != 1)
            {
                if (check(i, j - 1, 'D'))
                    path_matrix[i][j - 1] = -1;
                else if (check(i, j - 1, 'E'))
                    path_matrix[i][j - 1] = path_matrix[i][j];
                else
                    path_matrix[i][j - 1] = 0;
            }

            if ((i - 1) >= 0 && path_matrix[i - 1][j] != 1)
            {
                if (check(i - 1, j, 'D'))
                    path_matrix[i - 1][j] = -1;
                else if (check(i - 1, j, 'S'))
                    path_matrix[i - 1][j] = path_matrix[i][j];
                else
                    path_matrix[i - 1][j] = 0;
            }
        }
    }

    int num_paths = (path_matrix[0][0] ? 1 : 0);

    for (int i = 1; i < N; i++)
    {
        if (path_matrix[0][i] == 1)
            num_paths++;

        if (path_matrix[i][0] == 1)
            num_paths++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", path_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Number of possible starting points: %d\n", num_paths);
}

int check(int a, int b, char c)
{
    int x = 0;
    while (matrix[a][b][x] != '\0')
    {
        if (matrix[a][b][x] == c)
        {
            return 1;
        }
        x++;
    }

    return 0;
}

/*
Test cases:-

6
ES ES SE ES ES S
SE ES SE ES ES S
ES ES SE ES SE S
ES SE ES SE E D
SE ES D WSE NES NS
E E NE E E F

5
ES SE ES SE S
S EWS SE E S
E D SEW NSE S
NE N SEW D E
EN EN E EN F
*/