// { Driver Code Starts
//

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

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];

        Node *root = buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int Search(int in[], int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (x == in[start])
        {
            return i;
        }
    }
}

Node *myOwnBuildTree(int in[], int pre[], int start, int end)
{
    static int index = 0;
    if (start > end)
    {
        return NULL;
    }
    Node *tNode = new Node(pre[index++]);
    if (start == end)
    {
        return tNode;
    }
    int search = Search(in, start, end, tNode->data);
    tNode->left = myOwnBuildTree(in, pre, start, search - 1);
    tNode->right = myOwnBuildTree(in, pre, search + 1, end);
    return tNode;
}
Node *buildTree(int in[], int pre[], int n)
{
    return myOwnBuildTree(in, pre, 0, n - 1);
}
// int findIndex(int arr[], int start, int target)
// {
//     int i=0;
//     while( arr[start+i] != target ) i++;
//     return i;
// }

// Node* buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
// {
//     if(n==0) return NULL;

//     Node* ret = new Node( preorder[preStart] );

//     int i = findIndex( inorder, inStart, preorder[preStart] );

//     ret->left = buildUtil( inorder, preorder, inStart, preStart+1, i );
//     ret->right = buildUtil( inorder, preorder, inStart+i+1, preStart+i+1, n-i-1 );

//     return ret;
// }

// Node *buildTree(int inorder[], int preorder[], int n)
// {
//     return buildUtil(inorder, preorder, 0, 0, n);
// }