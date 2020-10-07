#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            length += 1;
        }
    }
    void printForward(Node *n)
    {
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
    }
    void printBackward(Node *n)
    {
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->prev;
        }
    }
    void pop()
    {
        tail = tail->prev;
        tail->next = NULL;
        length -= 1;
    }
    void shift()
    {
        head = head->next;
        head->prev = NULL;
        length -= 1;
    }
    void unshift(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length += 1;
    }
    int get(int index)
    {
        if (index >= length)
            return 0;
        int count = 0;
        Node *newnode = head;
        while (count != index)
        {
            newnode = newnode->next;
            ;
            count += 1;
        }
        return newnode->data;
    }
    void set(int index, int value)
    {
        if (index > length)
            return;
        Node *newNode = head;
        int count = 0;
        while (index != count)
        {
            newNode = newNode->next;
            count += 1;
        }
        newNode->data = value;
        return;
    }
};
int main()
{
    DoublyLinkedList list;
    for (int i = 0; i < 25; i++)
    {
        list.push(i);
    }
    list.printForward(list.head);
    cout << "\n";
    list.pop();
    list.printForward(list.head);
    cout << "\n";
    list.shift();
    list.printForward(list.head);
    cout << "\n";
    list.unshift(0);
    list.printForward(list.head);
    cout << "\n";
    cout << list.get(3);
    cout << "\n";
    list.set(0, 99);
    list.printForward(list.head);
}
