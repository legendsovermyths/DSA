// { Driver Code Starts
//Author- SAJAL AGRAWAL
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *r, int num);
int sumOfLeafNodes(Node *r);
void preOrderDisplay(Node *r);
void inOrderDisplay(Node *r);
void postOrderDisplay(Node *r);
int search(Node *r, int num);

int main(void)
{
    int t, n, data;
    scanf("%d", &t);
    while (t--)
    {
        Node *root = NULL;
        scanf("%d", &n);
        //printf("n=%d\n",n);
        while (n--)
        {
            scanf("%d", &data);
            //printf("data=%d\n",data);
            root = insert(root, data);
        }
        //inOrderDisplay(root);
        printf("%d\n", sumOfLeafNodes(root));
    }
    return 0;
}

Node *insert(Node *r, int num)
{
    if (r == NULL)
    {
        r = new Node(num);
    }
    else
    {
        if (num < r->data)
        {
            r->left = insert(r->left, num);
        }
        else
        {
            r->right = insert(r->right, num);
        }
    }
    return r;
}

void preOrderDisplay(Node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

void inOrderDisplay(Node *r)
{
    if (r != NULL)
    {
        inOrderDisplay(r->left);
        printf("%d ", r->data);
        inOrderDisplay(r->right);
    }
}

void postOrderDisplay(Node *r)
{
    if (r != NULL)
    {
        postOrderDisplay(r->left);
        postOrderDisplay(r->right);
        printf("%d ", r->data);
    }
}

int search(Node *r, int num)
{
    if (r == NULL)
        return 0;
    else if (r->data == num)
        return 0;
    else if (r->data > num)
        search(r->left, num);
    else
        search(r->right, num);
} // } Driver Code Ends

/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */

/*You are required to complete below method */
void Sum(Node *r, int &sum, int currLevel, int height)
{
    if (r == NULL)
        return;
    if (r->left == NULL && r->right == NULL)
    {
        sum += r->data;
    }
    Sum(r->left, sum, currLevel + 1, height);
    Sum(r->right, sum, currLevel + 1, height);
}
int height(Node *r)
{
    if (r == NULL)
        return 0;
    int leheight = height(r->left);
    int rheight = height(r->right);
    if (leheight > rheight)
        return 1 + leheight;
    return 1 + rheight;
}
int sumOfLeafNodes(Node *r)
{
    int sum = 0;
    int currLevel = 1;
    Sum(r, sum, currLevel, height(r));
    return sum;
}
