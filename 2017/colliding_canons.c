#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238

int main(void)
{
    int D, h;
    scanf("%d,%d", &D, &h);

    float theta1, theta2, s1, s2;
    scanf("%f,%f,%f,%f", &theta1, &s1, &theta2, &s2);

    float x1 = -D/2, y1 = 0, x2 = D/2, y2 = 0;

    theta1 = (PI / 180) * theta1;
    theta2 = (PI / 180) * theta2;

    float k = D / sin(theta1 + theta2);
    float t1 = k * sin(theta2) / s1, t2 = k * sin(theta1) / s2;

    printf("time1: %f, time2: %f\n", t1, t2);
    if (fabs(t1 - t2) <= .5)
    {
        float x = s1 * cosf(theta1) * t1 - D /2;
        float y = s1 * sinf(theta1) * t1;

        while (y > h / 2 || y < -h/2)
        {
            if (y > h / 2)
                y = h - y;
            else if(y < -h/2)
                y = h + y;
        }

        printf("Yes, %.2f, %.2f\n", x, y);
    }
    else
    {
        printf("No\n");
    }


}

/*
Test cases:-

input
500,2000
80,70,85,70

output
Yes, 84.19, 104.74


input
500,2000
30,90,40,70

output
Yes,46.20,171.01



input
500,2000
30,170,50,160

output
No
*/

