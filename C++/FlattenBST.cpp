#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void inorder(node *curr, node *&prev)
{
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
void print(node *parent)
{

    node *curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
node *Flatten(node *root)
{
    node *dummy = new node(-1);
    node *prev = dummy;
    inorder(root, prev);
    node *toReturn = dummy->right;
    delete dummy;
    return toReturn;
}
int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
    print(Flatten(root));
    return 0;
}