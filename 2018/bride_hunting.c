#include <stdio.h>

#define N 100
#define M 100

int bride_matrix[N][M];

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &bride_matrix[i][j]);

    bride_matrix[0][0] = 0;

    int x = 0;
    int index_mat[3][20];
    index_mat[0][x] = 0, index_mat[1][x] = 0, index_mat[2][x] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int Q_count = 0;

            if (i == 0 && j == 0)
                continue;


            if (bride_matrix[i][j])
            {
                if (i - 1 != -1)
                {
                    if ((j - 1) != -1 && bride_matrix[i - 1][j - 1])
                        Q_count++;

                    if ((j + 1) != m && bride_matrix[i-1][j+1])
                        Q_count++;

                    if (bride_matrix[i - 1][j])
                        Q_count++;
                }

                if ((i + 1) != n)
                {
                    if (j - 1 != -1 && bride_matrix[i + 1][j - 1])
                        Q_count++;

                    if ((j + 1) != m && bride_matrix[i + 1][j+1])
                        Q_count++;

                    if (bride_matrix[i + 1][j])
                        Q_count++;
                }


                if ((j - 1) != -1 && bride_matrix[i][j - 1])
                    Q_count++;

                if ((j + 1) != m && bride_matrix[i][j+1])
                    Q_count++;

                printf("qualities at {%d, %d} : %d\n", i + 1, j + 1, Q_count);
            }

            if (index_mat[2][x] < Q_count)
            {
                x = 0;
                index_mat[0][x] = i;
                index_mat[1][x] = j;
                index_mat[2][x] = Q_count;
            }
            else if(index_mat[2][x] == Q_count)
            {
                if (index_mat[0][x] + index_mat[1][x] > i + j)
                {
                    x = 0;
                    index_mat[0][x] = i;
                    index_mat[1][x] = j;
                    index_mat[2][x] = Q_count;
                }
                else if(index_mat[0][x] + index_mat[1][x] == i + j)
                {
                    x++;
                    index_mat[0][x] = i;
                    index_mat[1][x] = j;
                    index_mat[2][x] = Q_count;
                }
            }
        }
    }

    if (x == 0)
        printf("%d:%d:%d\n", index_mat[0][x] + 1, index_mat[1][x] + 1, index_mat[2][x]);
    else
        printf("Polygamy not allowed\n");
}