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
void doSomethingWithTheMap(vector<pair<Node *, int>> &m, int min, int max)
{

    for (int i = min; i <= max; i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            if (m[j].second == i)
            {
                cout << m[j].first->data << " ";
                break;
            }
        }
    }
    return;
}
void calculateMinMax(Node *root, int hd, int &min, int &max)
{
    if (root == NULL)
        return;
    if (hd < min)
        min = hd;
    if (hd > max)
        max = hd;
    calculateMinMax(root->left, hd - 1, min, max);
    calculateMinMax(root->right, hd + 1, min, max);
}
void fillTheMap(Node *root, vector<pair<Node *, int>> &m, int hd)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        m.push_back(make_pair(root->left, hd - 1));
    }
    if (root->right)
    {
        m.push_back(make_pair(root->right, hd + 1));
    }

    fillTheMap(root->left, m, hd - 1);
    fillTheMap(root->right, m, hd + 1);
}
void topView(struct Node *root)
{
    vector<pair<Node *, int>> m;
    int min = 1, max = -1;
    calculateMinMax(root, 0, min, max);
    int hd = 0;
    m.push_back(make_pair(root, 0));
    fillTheMap(root, m, hd);
    doSomethingWithTheMap(m, min, max);
    return;
}