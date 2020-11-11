#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *link = NULL;
    Node(int key)
    {
        data = key;
    }
};
void printList(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    return;
}
int main()
{
    Node *root = new Node(4);
    root->link = new Node(6);
    root->link->link = new Node(8);
    root->link->link->link = new Node(10);
    root->link->link->link->link = new Node(12);
    printList(root);
    Node *temp = root;
    temp = temp->link;
    temp = NULL;
    printList(root);
}