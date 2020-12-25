// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

struct node *Inorder(struct node *root)
{

    if (root->left == NULL)
        return root;
    Inorder(root->left);
}

void populateNext(struct node *root);

void insert(struct node *root, int n1, int n2, char lr)
{
    if (root == NULL)
        return;
    if (root->data == n1)
    {
        switch (lr)
        {
        case 'L':
            root->left = new node(n2);
            break;
        case 'R':
            root->right = new node(n2);
            break;
        }
    }
    else
    {
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        struct node *root = NULL;
        while (n--)
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;
            if (root == NULL)
            {
                root = new node(n1);
                switch (lr)
                {
                case 'L':
                    root->left = new node(n2);
                    break;
                case 'R':
                    root->right = new node(n2);
                    break;
                }
            }
            else
            {
                insert(root, n1, n2, lr);
            }
        }
        populateNext(root);

        struct node *ptr = Inorder(root);
        while (ptr)
        {
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* Set next of p and all descendents of p by traversing them in reverse Inorder */

/*
Node Structure

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};
*/
void inOrderP(node *root, vector<node *> &m)
{
    if (root == NULL)
        return;
    inOrderP(root->left, m);
    m.push_back(root);
    inOrderP(root->right, m);
}
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}
void populateNext(struct node *p)
{
    vector<node *> m;
    inOrderP(p, m);
    for (int i = 0; i < m.size() - 1; i++)
    {
        m[i]->next = m[i + 1];
    }
}