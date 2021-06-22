#include <stdio.h>

int n;
double sv, csv, psv, cv, r, cr, pr, ce, ca;


void input();
int input_constraints();
int CSV_CR_constraint();
void output();
int output_constraints();


int main(void)
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        input();

        int i = input_constraints();
        if (i == -1)
        {
            printf("Invalid Input\n");
            continue;
        }

        int c = CSV_CR_constraint();
        if (c == -1)
        {
            printf("Invalid Input\n");
            continue;
        }

        output();

        int o = output_constraints();
        if (o == -1)
        {
            printf("Invalid Input\n");
            continue;
        }

        printf("%0.2lf\n%0.2lf\n%0.2lf\n%0.2lf\n%0.2lf\n",
                psv, pr, cv, ce, ca);

    }

}

int output_constraints()
{
    if (psv < 20 || psv > 10000)
        return -1;

    if (pr < 0.01 || pr > 99.99)
        return -1;

    return 1;
}

void output()
{
    psv = sv - csv;
    cv = n * (sv < psv ? sv : psv);
    pr = r - cr;
    ce = cv * 0.5;
    ca = ce * (pr < r ? pr : r) * 0.01;
}


int CSV_CR_constraint()
{
    if (csv < 0)
    {
        if (cr > 0)
            return -1;
    }

    return 1;
}


int input_constraints()
{
    if (n < 20000 || n > 10000000)
        return -1;

    if (sv < 20 || sv > 10000)
        return -1;

    if (csv < -2000 || csv > 2000)
        return -1;

    if (r < 0.01 || r > 99.99)
        return -1;

    if (cr < -10 || cr > 10)
        return -1;

    return 1;
}


void input()
{
    scanf("%d %lf %lf %lf %lf", &n, &sv, &csv, &r, &cr);
}

/*

Input:-
4
25000
35
5
85
6
20000
19
2
60
3
25658
520
510
65
3
22000
30
-5
46
6

Output:-
30.00
79.00
750000.00
375000.00
296250.00
Invalid Input
Invalid Input
Invalid Input

*/