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
        if (length == 0)
        {
            newNode->data = val;
            head = newNode;
            tail = head;
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
    void pop()
    {
        Node *prev = head;
        while (prev->link->link != NULL)
        {
            prev = prev->link;
        }
        tail = prev;
        tail->link = NULL;
        length -= 1;
        if (length == 0)
        {
            head->link = NULL;
            tail->link = NULL;
        }
    }
    void shift()
    {
        if (length == 0)
        {
            return;
        }
        else
        {
            head = head->link;
            length -= 1;
        }
    }
    void unshift(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->link = head;
        head = newNode;
        length += 1;
    }
    void printList(Node *n)
    {
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->link;
        }
    }
    int get(int val)
    {
        if (val >= length)
            return 0;
        int count = 0;
        Node *cur;
        cur = head;
        while (val != count)
        {
            cur = cur->link;
            count += 1;
        }
        return cur->data;
    }
};
int main()
{
    SinglyLinkedList l1;
    l1.push(10);
    l1.push(11);
    l1.push(13);
    l1.push(23);
    l1.push(15);
    l1.printList(l1.head);
    l1.shift();
    cout << "\n";
    l1.printList(l1.head);
    l1.unshift(99);
    cout << "\n";
    l1.printList(l1.head);
    int give = l1.get(2);
    cout << "\n";
    cout << give;
}