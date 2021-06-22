#include <stdio.h>
#include <stdlib.h>


#define MONTHS 12
#define days_in_a_year 365

int main (void)
{
    int N, Rtv, Rntv, target;

    scanf("%d", &N);
    scanf("%d%d", &Rtv, &Rntv);
    scanf("%d", &target);

    int DIM[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int num_patients[days_in_a_year];
    int size = 0;

    //printf("Months\tday\ttotal patients\ttotal accomodation\n");
    for (int i = 0; i < MONTHS; i++)
    {
        for (int j = 0; j < DIM[i]; j++)
        {
            int cal = (6 - (i + 1)) * (6 - (i + 1)) + abs(j + 1 - 15);
            num_patients[size] = (cal < N ? cal : N);
            //printf("%d\t%d\t%d\t%d\n", (i+ 1), (j + 1), cal, num_patients[size]);
            size++;
        }
    }

    for (int i = 0; i <= N; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            if (num_patients[j] > (N - i))
            {
                sum += (N - i) * Rntv + (num_patients[j] - (N - i)) * Rtv;
            }
            else
            {
                sum += Rntv * num_patients[j];
            }
        }

        if (sum >= target)
        {
            printf("sum: %d, at %d tv rooms\n", sum, i);
            return 0;
        }
    }

    printf("%d\n", N);
}