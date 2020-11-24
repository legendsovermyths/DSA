// { Driver Code Starts
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

void topView(struct Node *root);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n;
        i = n;

        Node *root = NULL;
        queue<Node *> q;
        while (i > 0)
        {
            int a, b;
            char c;
            cin >> a >> b >> c;
            if (!root)
            {
                root = new Node(a);
                q.push(root);
            }
            Node *pick = q.front();
            q.pop();

            if (c == 'L')
            {
                pick->left = new Node(b);
                q.push(pick->left);
            }
            cin >> a >> b >> c;
            if (c == 'R')
            {
                pick->right = new Node(b);
                q.push(pick->right);
            }
            i -= 2;
        }
        //        inorder(root);
        //        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void calculateMinMax(int *min, int *max, Node *root, int hd)
{
    if (root == NULL)
    {
        return;
    }
    if (*min > hd)
    {
        *min = hd;
    }
    if (*max < hd)
    {
        *max = hd;
    }
    calculateMinMax(min, max, root->left, hd - 1);
    calculateMinMax(min, max, root->right, hd + 1);
}
void printCurrentLine(Node *root, int hd, int line)
{
    if (root == NULL)
    {
        return;
    }
    if (hd == line)
    {
        cout << root->data << " ";
    }
    printCurrentLine(root->left, hd - 1, line);
    printCurrentLine(root->right, hd + 1, line);
}
void verticalTraversal(Node *root)
{
    int max = -1, min = 0;
    calculateMinMax(&min, &max, root, 0);
    cout << "min" << min << endl;
    cout << "max" << max << endl;
    for (int line = min; line <= max; line++)
    {
        printCurrentLine(root, 0, line);
        cout << endl;
    }
    return;
}
void topView(struct Node *root)
{
    verticalTraversal(root);
    return;
}