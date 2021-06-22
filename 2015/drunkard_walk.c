#include <stdio.h>


int walk(int F, int B, int T, int FD, int BD, int *dir);
int main(void)
{
    int test;
    scanf("%d", &test);

    while (test--)
    {
        char buffer = getchar();
        char D;
        int FM, BM, T, FBS, BBS;
        scanf("%c %d %d %d %d %d", &D, &FM, &BM, &T, &FBS, &BBS);

        if (D == 'F')
        {
            int dir;
            char x;
            int t = walk(FM, BM, T, FBS, BBS, &dir);
            if (t == -1)
            {
                printf("Hurray\n");
            }
            else
            {
                if (dir == 0)
                    x = 'F';
                else
                    x = 'B';

                printf("%d %c\n", t, x);
            }

        }
        else if (D == 'B')
        {
            int dir;
            char x;
            int t = walk(BM, FM, T, BBS, FBS, &dir);
            if (t == -1)
            {
                printf("Hurray\n");
            }
            else
            {
                if (dir == 0)
                    x = 'B';
                else
                    x = 'F';

                printf("%d %c\n", t, x);
            }
        }
    }
}


int walk(int F, int B, int T, int FD, int BD, int *dir)
{
    if (FD <= F)
    {
        *dir = 0;
        return (FD * T);
    }


    if (F == B)
        return -1;
    else if (F > B)
    {
        *dir = 0;
        int n = (FD - F)/(F - B);
        if ((FD - F) % (F - B) == 0)
        {
            return (n * (F + B) + F) * T;
        }
        else
        {
            return ((n + 1) * (F + B) + F + B + FD - ((n + 1) * (F - B))) * T;
        }
    }
    else // if (B > F)
    {
        *dir = 1;
        int n = BD/(B - F);
        if (BD % (B - F) == 0)
        {

            return (n * (F + B)) * T;
        }
        else
        {
            return (n * (F + B) + F + BD - (n * (B - F)) + F) * T;
        }
    }
}

/*
Input:-
6
B 14 12 7 25 4
B 11 4 6 10 17
F 2 3 9 12 15
F 1 12 3 22 28
B 8 8 5 9 18
F 8 8 5 7 9

Output:-
28 B
156 F
675 B
102 B
Hurray
35 F
*/