#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* left, *right;
    
};

struct tree *root = NULL, *temp, *newnode;

void Insert(int m)
{
    newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = m;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
        root = newnode;
    else
    {
        int flag = 1;
        temp = root;
        while(flag != 0)
        {
            if(newnode->data < temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = newnode;
                    flag = 0;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = newnode;
                    flag = 0;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

void printInorder(struct tree* root)
{  
    if(root != NULL)
    {
        printInorder(root->left);
        printf("%d\t", root->data);
        printInorder(root->right);
    }
}
int search(struct tree* root, int d)
{
    if(root->data == d)
            return 1;
    else if(root->data > d)
        return search(root->left, d);
    else if(root->data < d)
        return search(root->right, d);
}

int main()
{
    Insert(10);
    Insert(7);
    Insert(11);
    Insert(20);
    Insert(9);
    Insert(21);
    printInorder(root);
    int status = search(root, 110);
    if(status == 1)
        printf("\nData found");
    else    
        printf("\nData not found");
}