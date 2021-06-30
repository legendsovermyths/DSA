#include <bits/stdc++.h>
using namespace std;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define loop(k, n) for (int k = 0; k < n; k++)
#define deb(x) cout << #x << "= " << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define Loop(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define ll long long
#define PI 3.1415926535897932384626
typedef vector<int> vi;
typedef vector<ll> vl;

class Node
{
public:
    Node *left = NULL;
    Node *right = NULL;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int SumTree(Node *root, int &largest)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int sum = root->data + SumTree(root->left, largest) + SumTree(root->right, largest);
    if (sum > largest)
    {
        largest = sum;
    }
    return sum;
}

int main()
{
    int largest = 0;
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    root->right->left = new Node(-6);
    SumTree(root, largest);
    cout << largest << endl;
}