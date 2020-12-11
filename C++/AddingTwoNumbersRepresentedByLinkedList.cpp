// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

struct Node *addTwoLists(struct Node *first, struct Node *second);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node *Shift(Node *head, int val)
{
    if (head == NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
        return head;
    }
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
}
Node *ReverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    first = ReverseLinkedList(first);
    second = ReverseLinkedList(second);
    Node *temp1 = first;
    Node *temp2 = second;
    Node *headOfTheLinkedListToBeReturned = NULL;
    int holdSum = 0;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        holdSum = temp1->data + temp2->data;
        headOfTheLinkedListToBeReturned = Shift(headOfTheLinkedListToBeReturned, (holdSum + carry) % 10);
        carry = (holdSum + carry) / 10;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        holdSum = temp1->data;
        headOfTheLinkedListToBeReturned = Shift(headOfTheLinkedListToBeReturned, (holdSum + carry) % 10);
        carry = (holdSum + carry) / 10;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        holdSum = temp2->data;
        headOfTheLinkedListToBeReturned = Shift(headOfTheLinkedListToBeReturned, (holdSum + carry) % 10);
        carry = (holdSum + carry) / 10;
        temp2 = temp2->next;
    }
    if (carry > 0)
    {
        headOfTheLinkedListToBeReturned = Shift(headOfTheLinkedListToBeReturned, carry);
    }
    return headOfTheLinkedListToBeReturned;
}