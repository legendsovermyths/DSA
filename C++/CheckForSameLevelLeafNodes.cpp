// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool check(Node *node);

// Driver program to test size function
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        cout << check(head) << endl;
    }
    return 0;
}
// } Driver Code Ends

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*You are required to complete this method*/
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
        return lheight + 1;
    return rheight + 1;
}
void LevelOrder(int currLevel, int height, Node *root, vector<bool> &checker)
{
    if (root == NULL)
    {
        checker.push_back(true);
        return;
    }
    else if (root->right == NULL && root->left == NULL && height == currLevel)
    {
        checker.push_back(true);
        return;
    }
    else if (root->right != NULL || root->left != NULL)
    {
        LevelOrder(currLevel + 1, height, root->left, checker);
        LevelOrder(currLevel + 1, height, root->right, checker);
    }
    else
    {
        checker.push_back(false);
        return;
    }
}
bool check(Node *root)
{
    vector<bool> checker;
    int heigh = height(root);
    int currLevel = 1;
    LevelOrder(currLevel, heigh, root, checker);
    for (int i = 0; i < checker.size(); i++)
        if (checker[i] == 0)
            return false;
    return true;
}
//1691 6733 N 5989 6640 N 2750 3565 N 1371 5003 N 1677 8921 N 8413 7729 N 7679 2475 N 2822 6415 N 3872