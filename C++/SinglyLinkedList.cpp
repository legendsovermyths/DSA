#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node()
    {
        next = nullptr;
    }
    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    Node head;
    Node tail;
    int length = 0;
    SinglyLinkedList(){};
    void push(int val)
    {
        Node newNode = Node(val);
        if (head.next == nullptr)
        {
            head = newNode;
            head.next = &newNode;
            tail = newNode;
            length += 1;
        }
        else
        {
            tail.next = &newNode;
            tail = newNode;
            length += 1;
        }
    }
};
int main()
{
    SinglyLinkedList list1 = SinglyLinkedList();
    list1.push(12);
    list1.push(13);
    list1.push(15);
    cout << list1.head.next->value << endl;
}