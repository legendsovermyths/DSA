// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node *buildTree(string str)
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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
void InorderP(Node *root, string &m)
{
    if (root == NULL)
        return;
    InorderP(root->left, m);
    m = m + to_string(root->data);
    InorderP(root->right, m);
}
bool dupSub(Node *root)
{
    unordered_set<string> pop;
    string m = "";
    Node *temp = root;
    queue<Node *> q;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
        {
            InorderP(temp->left, m);
            if (pop.find(m) != pop.end() && m.length() >= 3)
            {
                cout << "k";
                return true;
            }

            pop.insert(m);
            q.push(temp->left);
            m = "";
        }
        if (temp->right)
        {
            InorderP(temp->right, m);
            if (pop.find(m) != pop.end() && m.length() >= 3)
            {
                cout << m << " ";
                return true;
            }

            pop.insert(m);
            q.push(temp->right);
            m = "";
        }
    }
    return false;
}

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    //cout << t << "\n";
    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node *root = buildTree(treeString);
        //Solution ob;
        cout << dupSub(root) << "\n";
    }
    return 0;
} // } Driver Code Ends