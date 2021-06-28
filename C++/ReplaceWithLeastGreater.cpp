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
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

Node *insert(Node *root, Node *&succ, int key)
{
    if (root == NULL)
    {
        Node *newNode = new Node(key);
        return newNode;
    }
    if (root->data > key)
    {
        succ = root;
        root->left = insert(root->left, succ, key);
    }
    if (root->data < key)
    {
        root->right = insert(root->right, succ, key);
    }
    return root;
}

void solution(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {

        Node *succ = NULL;
        root = insert(root, succ, arr[i]);
        if (succ)
        {
            ans[i] = succ->data;
        }
        else
        {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92,
                       43, 3, 91, 93, 25, 80, 28};
    solution(arr);
}