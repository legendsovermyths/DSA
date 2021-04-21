// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

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

int sumOfLongRootToLeafPath(Node *root);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d", &n);
        struct Node *root = NULL;
        struct Node *child;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << sumOfLongRootToLeafPath(root) << endl;
    }
    return 0;
} // } Driver Code Ends

//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function

void Sum(Node *root, vector<int> &sum, int add, int height, int curr)
{
    if (root == NULL)
        return;
    add = add + root->data;
    if (curr == height)
    {
        sum.push_back(add);
        return;
    }

    Sum(root->left, sum, add, height, curr + 1);
    Sum(root->right, sum, add, height, curr + 1);
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return (1 + lheight);
        else
            return (1 + rheight);
    }
}
int sumOfLongRootToLeafPath(Node *root)
{
    vector<int> sum;
    int add = 0;
    int heigh = height(root);
    Sum(root, sum, add, heigh, 1);
    return *max_element(sum.begin(), sum.end());
}