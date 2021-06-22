#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define fi(x, y) for (int i = x; i < y; i++)
#define fj(x, y) for (int j = x; j < y; j++)
#define fk(x, y) for (int k = x; k < y; k++)


int rq[100], cq[100];
int front = -1, rear = -1;


int move_count = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;


int explo[2][3];
int num_explo = 0, n, m, basei, basej;
int *grid, *visited;

void displayd(int *arr);
void displayc(char *arr);
void preprocessing(int x, int y);
void explore_neighbour(int r, int c, int k);
void find_path();

int main(void)
{
    scanf("%d %d", &n, &m);

    grid = (int *) malloc(n * m * sizeof(int));
    visited = (int *) malloc(n * m * sizeof(int));
    memset(visited, 0, n * m * sizeof(int));

    fi (0, n)
    {
        char ch, buffer;
        buffer = getchar();
        fj (0, m)
        {
            scanf("%c", &ch);
            if (ch == 'w')
            {
                *(grid + i * m + j) = -1;
            }
            else if (ch == 's')
            {
                explo[0][num_explo] = i;
                explo[1][num_explo] = j;
                num_explo++;
            }
            else if (ch == 'd')
            {
                basei = i, basej = j;
            }
        }
    }

    int tmp;
    scanf("%d", &tmp);

    preprocessing(basei, basej);
    displayd(grid);
    find_path();

    free(grid);
    free(visited);
}

void find_path()
{
    int dr[] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dc[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    char *output = malloc(n * m * sizeof(char));

    fk (0, num_explo)
    {
        fi (0, n)
            fj (0, m)
                if (*(grid + i*m + j) == -1)
                    *(output + i*m + j) = 'w';
                else
                    *(output + i*m + j) = '-';
        *(output + basei*m + basej) = 'd';


        int r = explo[0][k];
        int c = explo[1][k];

        while (r != basei || c != basej)
        {
            int found = 0;
            *(output + r * m + c) = 97 + k;
            fi (0, 8)
            {

                int rr = r + dr[i], cc = c + dc[i];
                if (rr < 0 || cc < 0 || rr >= n || cc >= m)
                    continue;

                if (*(grid + rr * m + cc) == *(grid + r * m + c) - 1)
                {
                    found = 1;
                    r = rr, c = cc;
                    break;
                }
            }
        }

        displayc(output);
        printf("\n");
    }
    free(output);
}

void preprocessing(int x, int y)
{
    rear++;
    rq[rear] = x, cq[rear] = y;
    *(grid + x * m + y) = move_count;
    *(visited + x * m + y) = 1;

    move_count++;
    while (front != rear)
    {
        front++;
        int r = rq[front], c = cq[front];


        explore_neighbour(r, c, move_count);
        nodes_left_in_layer--;
        if (nodes_left_in_layer == 0)
        {
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }

    }
}


void explore_neighbour(int r, int c, int k)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue;

            int rr = r + i, cc = c + j;

            if (rr < 0 || cc < 0 || rr >= n || cc >= m)
                continue;

            if (*(visited + rr * m + cc) || *(grid + rr * m + cc) == -1)
                continue;

            rear++;
            rq[rear] = rr, cq[rear] = cc;
            nodes_in_next_layer++;
            *(grid + rr * m + cc) = k;
            *(visited + rr * m + cc) = 1;
        }
    }
}

void displayd(int *arr)
{
    fi (0, n)
    {
        fj (0, m)
        {
            printf("%d ", *(arr + i*m + j));
        }
        printf("\n");
    }
}

void displayc(char *arr)
{
    fi (0, n)
    {
        fj (0, m)
        {
            printf("%c ", *(arr + i*m + j));
        }
        printf("\n");
    }
}

/*
input1:-
4 4
w-d-
w-w-
w-ww
s--s
-1

input2:-
4 4
s--s
----
----
s--d
-1
*/