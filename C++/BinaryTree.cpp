#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *newNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *insertNode(int data, Node *root)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = newNode(data);
            return root;
        }
        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = newNode(data);
            return root;
        }
    }
    return root;
}
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (1 + lheight);
        else
            return (1 + rheight);
    }
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    Node *temp;
    int level = height(root);
    int MinLevel = level;
    q.push(root);
    cout << root->data << " ";
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
        {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }
        if (temp->right)
        {
            cout << temp->right->data << " ";
            q.push(temp->right);
        }
    }
}
void levelorderRecursive(Node *root, int height)
{
    if (root == NULL)
    {
        return;
    }
    if (height == 0)
    {
        cout << root->data << " ";
    }
    if (root->left)
    {
        cout << root->left->data << " ";
    }
    if (root->right)
    {
        cout << root->right->data << " ";
    }
    levelorderRecursive(root->left, height - 1);
    levelorderRecursive(root->right, height - 1);
}
void calculateMinMax(int &min, int &max, int hd, Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (min > hd)
    {
        min = hd;
    }
    if (max < hd)
    {
        max = hd;
    }
    calculateMinMax(min, max, hd + 1, root->right);
    calculateMinMax(min, max, hd - 1, root->left);
}
void printVerticalLine(int lineNo, Node *root, int hd)
{
    if (root == NULL)
    {
        return;
    }
    if (lineNo == hd)
    {
        cout << root->data << " ";
    }
    printVerticalLine(lineNo, root->left, hd - 1);
    printVerticalLine(lineNo, root->right, hd + 1);
}
void verticalOrderTraversal(Node *root)
{
    int min = 0, max = -1;
    calculateMinMax(min, max, 0, root);
    for (int lineNo = min; lineNo <= max; lineNo++)
    {
        printVerticalLine(lineNo, root, 0);
        cout << endl;
    }
    return;
}
void inorder(Node *temp)
{

    if (temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
void deleteDeepest(Node *root, Node *d_node)
{

    queue<Node *> q;
    q.push(root);
    struct Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
Node *deletion(int key, Node *root)
{

    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    queue<Node *> q;
    q.push(root);
    Node *qnode;
    Node *tempNode = NULL;

    while (!q.empty())
    {
        qnode = q.front();
        q.pop();
        if (qnode->data == key)
        {
            tempNode = qnode;
        }
        if (qnode->left)
        {
            q.push(qnode->left);
        }
        if (qnode->right)
        {
            q.push(qnode->right);
        }
    }
    if (tempNode != NULL)
    {
        int x = qnode->data;
        deleteDeepest(root, qnode);
        tempNode->data = x;
        return root;
    }
    return root;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    // cout << "Inorder traversal before deletion : ";
    // levelOrder(root);
    // int key = 11;
    // root = deletion(key, root);

    // cout << endl;
    // cout << "Inorder traversal after deletion : ";
    levelorderRecursive(root, 0);

    return 0;
}
