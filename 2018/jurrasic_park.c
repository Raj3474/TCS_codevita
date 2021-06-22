#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define INF 1000000

// park dimensions
int R, C;
int *pd, *pm;
int move_count, nodes_in_next_layer, nodes_left_in_layer;


int *dino, *gate1, *gate2, *gate3;
int *visited;

int g1r, g1c, g2r, g2c, g3r, g3c;
int dinor, dinoc;

// row_queues, column_queue
int rq[1000], cq[1000], front = -1, rear = -1;

void explore_neighbour(int *arr1, int *arr2, int r, int c, int val);
void solve(int *arr1, int *arr2, int sr, int sc);
void display(int *arr);
void set_memory(int a, int b);
void free_memory();

int main(void)
{
    scanf("%d %d", &R, &C);
    set_memory(R, C);
    scanf("%d %d %d %d %d %d %d %d", &g1r, &g1c, &g2r, &g2c,
                                     &g3r, &g3c, &dinor, &dinoc);
    g1r--, g1c--, g2r--, g2c--, g3r--, g3c--, dinor--, dinoc--;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char buffer = getchar();
            char ch = getchar();

            if (ch == 'W')
                *(pd + i*C + j) = -1, *(pm + i*C + j) = -1;
            else if (ch == 'M')
                *(pd + i*C + j) = 1, *(pm + i*C + j) = -1;
            else
                *(pd + i*C + j) = *(pm + i*C + j) = 1;
        }
    }
    solve(pd, dino, dinor, dinoc);
    solve(pm, gate1, g1r, g1c);
    solve(pm, gate2, g2r, g2c);
    solve(pm, gate3, g3r, g3c);


    // display(pd);
    // display(pm);
    // display(dino);
    // display(gate1);
    // display(gate2);
    // display(gate3);
    int total = 0, safe = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (*(pm + i*C + j) == 1)
            {
                total++;

                if (i == dinor && j == dinoc)
                    continue;
                if (*(dino + i*C + j) == INF)
                {
                    safe++;
                    continue;
                }
                if ((i == g1r && j == g1c) || (i == g2r && j == g2c ) || (i == g3r && j == g3c ))
                    safe++;
                else if (*(gate1 + i*C + j) <= *(dino + g1r*C + g1c))
                    safe++;
                else if (*(gate2 + i*C + j) <= *(dino + g1r*C + g1c))
                    safe++;
                else if (*(gate3 + i*C + j) <= *(dino + g1r*C + g1c))
                    safe++;
            }
        }
    }

    printf("total: %d, safe: %d\n", total, safe);
    free_memory();
}

void solve(int *arr1, int *arr2, int sr, int sc)
{
    memset(visited, 0, R * C * sizeof(int));
    front = rear = -1;
    move_count = 1, nodes_in_next_layer = 0, nodes_left_in_layer = 1;

    rear++;
    rq[rear] = sr, cq[rear] = sc;
    *(visited + sr*C + sc) = 1, *(arr2 + sr*C + sc) = move_count++;

    while (rear != front)
    {
        front++;
        int r = rq[front], c = cq[front];

        explore_neighbour(arr1, arr2, r, c, move_count);
        nodes_left_in_layer--;
        if (nodes_left_in_layer == 0)
        {
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }
    }
}

void explore_neighbour(int *arr1, int *arr2, int r, int c, int val)
{
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i], cc = c + dc[i];

        if (rr < 0 || cc < 0 || rr >= R || cc >= C)
            continue;

        if (*(visited + rr*C + cc) == 1 || *(arr1 + rr*C + cc) == -1)
            continue;

        *(visited + rr*C + cc) = 1;
        *(arr2 + rr*C + cc) = val;

        if ((rr == g1r && cc == g1c ) || (rr == g2r && cc == g2c ) || (rr == g3r && cc == g3c ))
            continue;

        rear++;
        rq[rear] = rr, cq[rear] = cc;
        nodes_in_next_layer++;
    }
}

void display(int *arr)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%d ", *(arr + i*C + j));
        }
        printf("\n");
    }
    printf("\n");
}

void set_memory(int a, int b)
{
    pd = malloc(a*b*sizeof(int));
    pm = malloc(a*b*sizeof(int));
    visited = malloc(a*b*sizeof(int));
    dino = malloc(a*b*sizeof(int));
    gate1 = malloc(a*b*sizeof(int));
    gate2 = malloc(a*b*sizeof(int));
    gate3 = malloc(a*b*sizeof(int));

    memset(dino, INF, a*b*sizeof(int));
    memset(gate1, INF, a*b*sizeof(int));
    memset(gate2, INF, a*b*sizeof(int));
    memset(gate3, INF, a*b*sizeof(int));
}

void free_memory()
{
    free(pd);
    free(pm);
    free(visited);
    free(dino);
    free(gate1);
    free(gate2);
    free(gate3);
}
/*

input:-
4 4
1 1 2 1 3 1 1 3
G G G G
G W W M
G G W W
M G M M

*/