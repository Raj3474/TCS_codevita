#include <stdio.h>
#include <string.h>


int is_anagram(char T[], char P[], int len1, int len2);
int main(void)
{
    char s1[31];
    scanf("%s", s1);

    int len1 = strlen(s1);

    int q;
    scanf("%d", &q);

    char s2[q + 1];
    int len2 = 0, index = 0;

    while(q--)
    {
        char dir, garbage;
        int mag;

        garbage = getchar();
        scanf("%c", &dir);
        garbage = getchar();

        scanf("%d", &mag);

        int f = (dir == 'L' ? 1 : -1);
        index = (index + f * mag + len1) % len1;

        s2[len2] = s1[index];
        s2[len2 + 1] = '\0';
        len2++;
    }
    printf("%s\n", s2);

    if (is_anagram(s1, s2, len1, len2))
        printf("YES\n");
    else
        printf("NO\n");

}

int is_anagram(char T[], char P[], int len1, int len2)
{

    if (len1 < len2)
        return 0;

    int found;
    for (int i = 0; i <= len1 - len2; i++)
    {
        found = 1;
        for (int j = 0; j < len2; j++)
        {
            if (P[j] != T[i + j])
            {
                found = 0;
                break;
            }
        }
        if (found)
            return found;
    }
    return found;
}