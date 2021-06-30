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
        data = val;
        right = NULL;
        left = NULL;
    }
};

int Solution(Node *root, int key, int &k, int &ans)
{

    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    int l = Solution(root->left, key, k, ans);
    int r = Solution(root->right, key, k, ans);
    cout << k << " ";

    if (l || r)
    {

        k = k - 1;
    }
    if (k == 0 && ans == -1)
    {
        ans = root->data;
        return root->data;
    }
    if (l || r)
        return 1;
    return 0;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int k = 2;
    int ans = -1;
    Solution(root, 4, k, ans);
    cout << endl;
    cout << ans << endl;
    return 0;
}