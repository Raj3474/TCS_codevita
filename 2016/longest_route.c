#include <stdio.h>
#include <string.h>

int dp[100][100];
int visited[100][100];

int M, N, id, jd;

void find_route(int i, int j, int l);
int main(void)
{
    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(dp));

    scanf("%d %d", &M, &N);

    int H;
    scanf("%d", &H);

    while (H--)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        dp[x][y] = -1;
    }

    int is, js;
    scanf("%d %d", &is, &js);
    scanf("%d %d", &id, &jd);

    if (dp[is][is] == -1 || dp[id][id] == -1)
    {
        printf("-1\n");
        return 1;
    }

    find_route(is, js, 0);

    if (dp[id][jd])
        printf("longest possible route: %d\n", dp[id][jd]);
    else
        printf("-1\n");
}

void find_route(int i, int j, int l)
{
    //printf("i: %d, j: %d, dist: %d\n", i, j, l);



    if (i == id && j == jd)
    {
        if (dp[id][jd] < l)
            dp[id][jd] = l;
        return;
    }

    dp[i][j] = l;
    visited[i][j] = 1;

    if (i - 1 >= 0 && dp[i-1][j] != -1 && !visited[i - 1][j])
        find_route(i - 1, j, l + 1);

    if (i + 1 < M && dp[i + 1][j] != -1 && !visited[i + 1][j])
        find_route(i + 1, j, l + 1);

    if (j - 1 >= 0 && dp[i][j - 1] != -1 && !visited[i][j - 1])
        find_route(i, j - 1, l + 1);

    if (j + 1 < N && dp[i][j + 1] != -1 && !visited[i][j + 1])
        find_route(i, j + 1, l + 1);

    visited[i][j] = 0;
}