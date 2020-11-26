#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
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
};
int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    return 0;
}
