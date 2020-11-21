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
Node *CreateNode(int data)
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
        root = CreateNode(data);
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
            temp->right = CreateNode(data);
            return root;
        }
        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(data);
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
            level = height(temp->left);
            q.push(temp->left);
            if (level < MinLevel)
            {
                cout << temp->left->data << " ";
                MinLevel = level;
            }
        }
        if (temp->right)
        {
            q.push(temp->right);
            if (level < MinLevel)
            {
                MinLevel = level;
            }
        }
    }
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
    Node *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);

    // cout << "Inorder traversal before deletion : ";
    // levelOrder(root);
    // int key = 11;
    // root = deletion(key, root);

    // cout << endl;
    // cout << "Inorder traversal after deletion : ";
    levelOrder(root);

    return 0;
}
