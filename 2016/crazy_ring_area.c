#include <stdio.h>

#define del(a, b) (a - b)
#define PI 3.141592653

double x1, y1, x2, y2, x3, y3;

double Square_root(double num);
double area();
int main(void)
{

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);

    if (del(x3, x1) * del(y1, y2) == del(y3, y1) * del(x1, x2))
        printf("Not possible\n");
    else
    {
        double Area = area();

        double a_s = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        double b_s = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        double c_s = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);


        double s = (Square_root(a_s) + Square_root(b_s) + Square_root(c_s)) / 2;

        double result = (PI) * ((a_s * b_s * c_s) / (16 * Area * Area) - (Area * Area)/ (s * s));
        printf("%.2lf\n", result);
    }


}

double area()
{
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/ 2.0;
}

double Square_root(double num)
{
    if (num == 0)
        return 0;
    const double eps = 1E-6;
    double x = 1;
    while (1)
    {
        double nx = (x + num / x) / 2.0;

        if (nx > x && (nx - x) < eps)
            break;
        else if (x > nx && (x - nx) < eps)
            break;

        x = nx;
    }
    return x;
}

// double absolute(double a, double b)
// {
//     return ((a > b) ? (a - b) : (b - a));
// }