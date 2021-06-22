#include <stdio.h>
#include <string.h>


int main(void)
{
    int k;
    scanf("%d", &k);

    while (k--)
    {
        char s[401];
        int al[26];

        memset(al, 0, 26 * sizeof(int));

        scanf("%s", s);

        int i = 0;
        while (s[i] != '\0')
        {
            int j = s[i] - 97;
            //printf("J: %d\n", j);

            al[j]++;

            if (al[j] > j + 1)
            {
                printf("NO\n");
                return 0;
            }

            i++;
        }

        for (i = 0; i < 26; i++)
        {
            if (al[i] != 0 && al[i] != i + 1)
            {
                printf("NO\n");
                return 0;
            }
        }

        printf("YES\n");
    }
}

/*
Input:- 2
        bba
        scca

Output:- YES
         NO

*/