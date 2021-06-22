#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int m[100][100];
int visited[100][100];

int si, sj, radius;
float intensity;


int rq[100], cq[100];
int front = -1, rear = -1;


void explore_neighbour(int r, int c);
void solve();
int main(void)
{
    char input_file[100];
    scanf("%s", input_file);

    FILE *fptr;
    fptr = fopen(input_file,"r");

    fscanf(fptr, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fptr, "%d", &m[i][j]);
        }
    }

    fscanf(fptr, "%d %d", &si, &sj);
    fscanf(fptr, "%f", &intensity);
    fclose(fptr);

    si--, sj--;

    if (intensity <= 3.0)
        radius = -1;
    else if (intensity > 3.0 && intensity <= 5.0)
        radius = 1;
    else if (intensity > 5.0 && intensity <= 8.0)
        radius = 3;
    else
        radius = n;

    memset(visited, 0, n * n * sizeof(int));
    solve();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void solve()
{
    rear++;
    rq[rear] = si, cq[rear] = sj;
    visited[si][sj] = 1;

    if ((si - si) <= radius && abs(sj - sj) <= radius)
        m[si][sj] = 3;
    else
        m[si][sj] = 2;

    while (front != rear)
    {
        front++;
        int r = rq[front], c = cq[front];

        explore_neighbour(r, c);
    }
}

void explore_neighbour(int r, int c)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue;

            int rr = r + i, cc = c + j;

            if (rr < 0 || cc < 0 || rr >= n || cc >= n)
                continue;

            if (visited[rr][cc] || m[rr][cc] == 0)
                continue;

            rear++;
            rq[rear] = rr, cq[rear] = cc;
            visited[rr][cc] = 1;

            if (abs(rr-si) <= radius && abs(cc-sj) <= radius)
                m[rr][cc] = 3;
            else
                m[rr][cc] = 2;
        }
    }
}

/*
ouputs:-

Map1.txt
1 0 2 2
0 0 0 3
1 0 3 0
0 0 3 3

Map2.txt
0 3 3 0 2 0 2 0 2
0 0 0 3 2 2 2 2 0
3 3 3 0 2 0 0 2 2
3 3 3 3 0 2 0 0 0
0 3 0 3 2 0 0 0 0
3 0 0 0 0 2 2 2 2
3 3 3 3 2 0 2 2 2
0 0 2 2 0 2 2 2 2
1 0 2 2 2 2 0 0 2

Map3.txt
1 0 3 3
0 0 0 3
1 0 0 3
0 0 3 3

Map4.txt
1 0 2 2
0 0 0 2
1 0 0 2
0 0 2 2
*/