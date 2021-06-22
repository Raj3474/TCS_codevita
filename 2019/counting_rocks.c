#include <stdio.h>
#include <malloc.h>


typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;


int traverse(node *ptr, int min, int max);
node *insert(node *tree, int val);
node *get_node(int val);



int main(void)
{
    node *root = NULL;

    int S, R;
    scanf("%d %d", &S, &R);

    while (S--)
    {
        int x;
        scanf("%d", &x);

        root = insert(root, x);
    }

    int R_arr[R];

    for (int i = 0; i < R; i++)
    {
        int min, max;
        scanf("%d %d", &min, &max);

        R_arr[i] = traverse(root, min, max);
    }

    for (int i = 0; i < R; i++)
        printf("%d ", R_arr[i]);
}

int traverse(node *ptr, int min, int max)
{
    if (ptr == NULL)
        return 0;

    if (ptr -> data >= min && ptr -> data <= max)
        return (1 + traverse(ptr -> left, min, max) + traverse(ptr -> right, min, max));
    else if (ptr -> data < min)
        return traverse(ptr -> right, min, max);
    else
        return traverse(ptr -> left, min, max);

}

node *insert(node *tree, int val)
{
    node *p, *nodeptr, *parentptr;
    p = get_node(val);

    if (tree == NULL)
    {
        tree = p;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr -> data)
            {
                nodeptr = nodeptr -> left;
            }
            else
            {
                nodeptr = nodeptr -> right;
            }
        }

        if (val < parentptr -> data)
        {
            parentptr -> left = p;
        }
        else
        {
            parentptr -> right = p;
        }
    }



    return tree;
}


node *get_node(int val)
{
    node *p = (node *)malloc(sizeof(node));

    p -> left = NULL;
    p -> right = NULL;
    p -> data = val;

    return p;
}