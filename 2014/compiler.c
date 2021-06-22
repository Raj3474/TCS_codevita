#include <stdio.h>
#include <string.h>

char L[20000], stack[10000];


int main(void)
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int top = -1, main_func = 0, func_open = 0, num_intr, i;

        char tmp = getchar();
        scanf("%[^\n]%*c", L);

        if (L[0] != '{')
        {
            printf("Compilation Errors\n");
            continue;
        }

        stack[++top] = L[0];

        for (i = 1; L[i] != '\0'; i++)
        {
            char c = L[i];

            if (c == ' ')
                continue;

            if (top == -1)
                break;

            if (c == 'P' && func_open == 1 && main_func == 1)
            {
                if (num_intr > 100)
                    break;  // error
                else
                    num_intr++:
            }
            else if (c == '<' || c == '(' || c == '{')
            {
                if (c == '<')
                {
                    if (main_func == 1 || func_open == 1)
                    {
                        break;  //error
                    }
                    else
                    {
                        func_open = 1;
                    }
                }
                else if (c == '(')
                {
                    if (func_open == 1)
                    {
                        break;  // error
                    }
                    else
                    {
                        func_open = 1;
                        num_intr = 0;
                    }
                }
                else if (c == '{')
                {
                    if (func_open != 1)
                    {
                        break;  // error
                    }
                }

                // push to the stack
                stack[++top] = c;
            }
            else
            {
                // pop from stack
                char k = stack[top--];

                if (c == '>')
                {
                    if (k != '<')
                    {
                        //error();
                        break;
                    }
                    else
                    {
                        main_func = 1;
                        func_open = 0;
                    }

                }
                else if (c == ')')
                {
                    if (k != '(')
                    {
                        //error();
                        break;
                    }
                    else
                    {
                        func_open = 0;
                    }
                }
                else if (c == '}')
                {
                    if (k != '{')
                    {
                        //error();
                        break;
                    }
                }
            }
        }

        if (main_func == 1 && L[i] == '\0'  && top == -1 )
        {
            printf("No Compilation Errors\n");
        }
        else
        {
            printf("Compilation Erros\n");
        }
    }
}
