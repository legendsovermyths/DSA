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

vector<int> rightView(struct Node *root);

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

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> vec = rightView(root);
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
void levelorderRecursive(Node *root, int height, int &currHeight)
{
    if (root == NULL)
    {
        return;
    }
    if (height == 0)
    {
        return;
    }
    if (root->right && height < currHeight)
    {
        cout << root->right->data << " ";
        currHeight = height;
    }
    else if (root->left && height < currHeight)
    {
        cout << root->left->data << " ";
        currHeight = height;
    }
    levelorderRecursive(root->right, height - 1, currHeight);
    levelorderRecursive(root->left, height - 1, currHeight);
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
    {
        return lheight + 1;
    }
    return rheight + 1;
}
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

    for (int line = min; line <= max; line++)
    {
        printCurrentLine(root, 0, line);
        cout << endl;
    }
    return;
}
// vector<int> rightView(Node *root)
// {
//     vector<int> useless;
//     if (root == NULL)
//     {
//         return useless;
//     }
//     cout << root->data << " ";
//     int h = height(root);
//     levelorderRecursive(root, height(root) - 1, h);
//     return useless;
// }
vector<int> rightView(Node *root)
{
    vector<int> useless;
    verticalTraversal(root);
    return useless;
}