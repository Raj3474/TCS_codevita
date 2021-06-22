#include <stdio.h>
#include <math.h>

float rate[50], periods[50];


double cal_emi(float r, float period, int total_months);
double emi_fun(int T);
int main(void)
{
    int p;
    scanf("%d", &p);

    int T;
    scanf("%d", &T);

    double emi1 = 0, emi2 = 0;

    emi1 = emi_fun(T);
    emi2 = emi_fun(T);

    (emi1 < emi2) ? printf("Bank A\n") : printf("Bank B\n");
}

double emi_fun(int T)
{
    int N;
    double result = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%f%f", &periods[i], &rate[i]);
    }

    int i;
    for (i = 0; i < N - 1; i++)
    {
        result += cal_emi(rate[i], periods[i], T);
    }

    return result;
}

double cal_emi(float r, float period, int years)
{
    double result = period * (r / (1 - 1 / (1+ pow(r, 12 * years))));
    return result;
}