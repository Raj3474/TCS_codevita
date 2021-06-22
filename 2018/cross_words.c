#include <stdio.h>
#include <string.h>



int n, m;
char puzzle[50][50], words[15][50];
int visited[50][50];

// words variable
int words_len[15], is_word_taken[15];

// clues variable
int ci[15], cj[15], clue_len[15], clue_no[15], which_word[15];
char AD[15];



void marking_the_copy(int, int, int, char, int);
void fill_black(int, int, int);
int cp_into_puzzle(int, int);
void clue_length_in_grid();
void display_puzzle();
void find_clue_pos();
int solve(int);
void input();



int main(void)
{
    input();
    find_clue_pos();
    clue_length_in_grid();
    solve(0);
    display_puzzle();

    for (int i = 0; i < n; i++)
    {
        printf("%d,%c,%s\n", clue_no[i], AD[i], words[which_word[i]]);
    }
}

int solve(int clue_n)
{
    if (clue_n == m)
        return 1;

    for (int i = 0; i < m; i++)
    {
        if (words_len[i] == clue_len[clue_n] && !is_word_taken[i])
        {
            int c = cp_into_puzzle(clue_n, i);
            if (c == 1)
            {
                is_word_taken[i] = 1;
                int res = solve(clue_n + 1);
                if (res == 1)
                {
                    return 1;
                }
                marking_the_copy(ci[clue_n], cj[clue_n], words_len[clue_n], AD[clue_n], -1);
                is_word_taken[i] = 0;
            }
        }
    }
    return -1;
}

int cp_into_puzzle(int clue_num, int word_num)
{
    int r = ci[clue_num], c = cj[clue_num], rr = r, cc = c;
    char ch = AD[clue_num];

    for (int i = 0; i < words_len[word_num]; i++)
    {
        if (ch == 'A')
            cc = c + i;
        else if (ch == 'D')
            rr = r + i;

        if (visited[rr][cc] == 0)
            puzzle[rr][cc] = words[word_num][i];
        else if (puzzle[rr][cc] != words[word_num][i])
            return -1;
    }
    marking_the_copy(r, c, words_len[word_num], ch, 1);
    which_word[clue_num] = word_num;
    return 1;
}

void marking_the_copy(int r, int c, int l, char ch, int k)
{
    int rr = r, cc = c;
    for (int i = 0; i < l; i++)
    {
        if (ch == 'A')
            cc = c+i;
        else if (ch == 'D')
            rr = r+i;
        visited[rr][cc] += k;
    }
}

void clue_length_in_grid()
{
    for (int i = 0; i < m; i++)
    {
        int r = ci[i], c = cj[i], length = 0;
        char ch = AD[i];

        while (puzzle[r][c] != '#' && c < n && r < n)
        {
            //puzzle[r][c] = 'a';
            length++;
            if (ch == 'A')
                c++;
            else if (ch == 'D')
                r++;
        }
        clue_len[i] = length;
    }
}

void find_clue_pos()
{
    int x = 0, clue_numbering = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int is_across = 0, is_down = 0;
            if (puzzle[i][j] == '#')
                continue;

            // if across possible
            if ((j-1<0 || puzzle[i][j-1] == '#') &&
                (j+1<n && puzzle[i][j+1] != '#'))
            {
                is_across = 1;
                ci[x] = i, cj[x] = j;
                clue_no[x] = clue_numbering;
                AD[x] = 'A';
                x++;
            }

            // if down possible
            if ((i-1<0 || puzzle[i-1][j] == '#') &&
                (i+1<n && puzzle[i+1][j] != '#'))
            {
                is_down = 1;
                ci[x] = i, cj[x] = j;
                clue_no[x] = clue_numbering;
                AD[x] = 'D';
                x++;
            }

            if (is_across || is_down)
                clue_numbering++;
        }
    }
}
void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            int a, b;
            char x;
            scanf("%d,%d%c", &a, &b, &x);

            if (a == 0)
                break;
            fill_black(i, a-1, b);

            if (x == '\n')
                break;
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", words[i]);
        words_len[i] = strlen(words[i]);
    }
    memset(is_word_taken, 0, m * sizeof(int));
    memset(visited, 0, n*n * sizeof(int));
}

void fill_black(int a, int b, int l)
{
    for (int i = 0; i < l; i++)
        puzzle[a][b+i] = '#';
}

void display_puzzle()
{
    printf("\n\nSolved Puzzle:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


/*

Input1:-
5
5,1
1,1,3,1,5,1
0,0
1,1,3,1,5,1
1,1
5
EVEN
ACNE
CALVE
PLEAS
EVADE

output1:-
1,A,ACNE
2,D,CALVE
3,D,EVADE
4,A,PLEAS
5,A,EVEN

Input2:-
5
1,1
1,1,3,2
0,0
1,1,3,2
0,0
5
ASIAN
RISEN
FEAR
CLAWS
FALLS

output2:-
1,A,FEAR
1,D,FALLS
2,D,RISEN
3,A,CLAWS
4,A,ASIAN

*/