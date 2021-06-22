#include <stdio.h>
#include <math.h>

double x, y, Va, Vb;

double func(double t);
int main(void)
{
    scanf("%lf %lf %lf %lf", &x, &y, &Va, &Vb);
    if (x > 0 && y > 0 && Va > 0 && Vb > 0)
    {
        double prev_d = func(0);
        for (int t = 0; ; t++)
        {
            double curr_d = func((double)t);
            if (curr_d > prev_d)
                break;
            prev_d = curr_d;
        }

        if (prev_d != 0.00)
            printf("result: %0.11lf\n", prev_d);
        else
            printf("result: 0.0\n");

    }
    else
    {
        printf("Invalid Input\n");
        return 1;
    }


}

double func(double t)
{
    double result = sqrt((x-Va*t)*(x-Va*t) + (y-Vb*t)*(y-Vb*t));
    return result;
}