#include <stdio.h>


int pascal[21][21];

void create_pascal();
int main(void)
{
    create_pascal();

    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N, R;
        scanf("%d %d", &R, &N);

        int type1_table = N % R;
        int type2_table = R - type1_table;

        int combination = 1, r1 = N/R + 1, r2 = N/R;
        for (int i = 0; i < type1_table; i++)
        {
            combination = combination * pascal[N][r1];
            N -= r1;
        }

        for (int i = 0; i < type2_table; i++)
        {
            combination = combination * pascal[N][r2];
            N -= r2;
        }

        printf("result: %d\n", combination);
    }

}



void create_pascal()
{
    pascal[0][0] = 1;

    for (int i = 1; i <= 21; i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]);
    }
}

/*

Test cases:-

input:- 2 5
output:- 10

input:- 2 3
output:- 3

input:- 4 10
output:- 25200
*/