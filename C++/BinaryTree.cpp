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
Node *insertNode(int data, Node *temp)
{
}
void inorder(Node *temp)
{

    if (temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
int main()
{
    Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
    inorder(root);
}
