#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *link = NULL;
};
class SinglyLinkedList
{
public:
    Node *head = new Node();
    Node *tail = new Node();

    int length = 0;
    void push(int val)
    {
        Node *newNode = new Node();
        if (head->link == NULL)
        {
            newNode->data = val;
            head = newNode;
            tail = head;
            head->link = tail;
            length += 1;
        }
        else
        {
            newNode->data = val;
            tail->link = newNode;
            tail = newNode;
            length += 1;
        }
    }
    void printList(Node *n)
    {
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->link;
        }
    }
};
int main()
{
    SinglyLinkedList l1;
    l1.push(10);
    l1.push(11);
    l1.push(13);
    l1.printList(l1.head);
}