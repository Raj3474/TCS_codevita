#include <stdio.h>


int n;
int mat[1000][1000];


void update(int x, int y, int z, int angle);
void rotate(int angle);
void display_mat();
int main(void)
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    char query;
    int total_rotation = 0;
    while (1)
    {
        char tmp = getchar();
        scanf("%c", &query);

        if (query == 'A')
        {
            int s;
            scanf("%d", &s);

            rotate(s);
            display_mat();

            total_rotation += s;
        }
        else if (query == 'Q')
        {
            int x, y;
            scanf("%d %d", &x, &y);

            printf("%d\n", mat[x - 1][y - 1]);
        }
        else if (query == 'U')
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);


            update(x - 1, y - 1, z, total_rotation);
            display_mat();
        }
        else
        {
            break;
        }
    }

}

void rotate(int angle)
{
    int tmp_mat[n][n];

    angle /= 90;

    int iter = angle % 4;

    for (int i = 0; i < iter; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                tmp_mat[k][n - j - 1] = mat[j][k];
            }
        }

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                mat[x][y] = tmp_mat[x][y];
            }
        }
    }


}

void update(int x, int y, int z, int angle)
{
    angle /= 90;
    int lim = angle % 4;

    for (int i = 0; i < lim; i++)
    {
        int tmp = y;
        y = n - x - 1;
        x = tmp;
    }

    mat[x][y] = z;
}

void display_mat()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}