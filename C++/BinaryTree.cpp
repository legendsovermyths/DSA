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
    {
        queue<Node *> q;
        q.push(root);
        struct Node *temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == d_node)
            {
                temp = NULL;
                delete (d_node);
                return;
            }
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
    struct Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->left->right = CreateNode(12);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout << "Inorder traversal before deletion : ";
    inorder(root);
    int key = 11;
    root = deletion(key, root);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}
