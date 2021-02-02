#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *newNode(int data)
{
    node *temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
int main()
{
    vector<int> preOrder = {10, 5, 1, 7, 40, 50};
}