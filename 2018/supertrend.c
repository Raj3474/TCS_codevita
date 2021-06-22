#include <stdio.h>
#include <math.h>

#define MUL 3

float data[1000][10];
int n;


float max(float a, float b, float c);
float average(int s);
void cal_final_band();
void cal_basic_band();
void super_trend();
void prepare_data();
void buy_sell();
void cal_ATR();


int main(void)
{
    scanf("%d", &n);


    for (int i = 0; i < n; i++)
    {
        scanf("%f %f %f", &data[i][0], &data[i][1], &data[i][2]);
    }

    prepare_data();
    buy_sell();


    // printf("high:  low:   close:   ATR:   b upp bd  b low d  f upp bd  f low bd super trend\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         printf("%0.2f  ", data[i][j]);
    //     }
    //     printf("\n");
    // }
}

void prepare_data()
{
    cal_ATR();
    cal_basic_band();
    cal_final_band();
    super_trend();
}

void cal_ATR()
{
    for (int i = 1; i < n; i++)
    {
        data[i][3] = max(fabs(data[i][0] - data[i][1]),
                         fabs(data[i][0] - data[i-1][2]),
                         fabs(data[i][1] - data[i-1][2]));
    }

    for (int i = 11; i < n; i++)
    {
        data[i][4] = average(i - 1);
    }
}


void buy_sell()
{
    for (int i = 11; i < n; i++)
    {
        printf("supertrend: %.2f, current close:%.2f--", data[i][9], data[i][2]);
        if (data[i][9] > data[i][2])
            printf("buy\n");

        if (data[i][9] < data[i][2])
            printf("sell\n");
    }
}

void super_trend()
{
    for (int i = 11; i < n; i++)
    {
        if (data[i][2] <= data[i][7])
            data[i][9] = data[i][7];
        else
            data[i][9] = data[i][8];
    }
}


void cal_basic_band()
{
    for (int i = 11; i < n; i++)
    {
        float sum = (int)(((data[i][0] + data[i][1])/2) * 100 + .5);

        data[i][5] = sum / 100 + MUL * data[i][4];
        data[i][6] = sum / 100 - MUL * data[i][4];
    }
}

void cal_final_band()
{
    // data[11][7] = data[11][5];
    // data[11][8] = data[11][6];


    for (int i = 11; i < n; i++)
    {
        float x, y;

        if (data[i][5] < data[i-1][7] || data[i-1][2] > data[i-1][7])
            x = data[i][5];
        else
            x = data[i-1][7];

        if (data[i][6] > data[i-1][8] || data[i-1][2] > data[i-1][8])
            y = data[i][6];
        else
            y = data[i-1][8];


        data[i][7] = x;
        data[i][8] = y;
    }
}


float average(int s)
{
    float sum = 0;
    for (int i = s; i > s - 10; i--)
    {
        sum += data[i][3];
    }

    float avg = (int)(sum * 10 + .5);
    return (avg/100);
}



float max(float a, float b, float c)
{
    a = (a > b) ? a : b;
    a = (a > c) ? a : c;
    return a;
}