// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

Node *addOne(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }

        head = addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends

//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
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
Node *addOne(Node *head)
{
    head = ReverseLinkedList(head);
    Node *temp = head;
    int holdSum = temp->data + 1;
    Node *newNode = NULL;
    int carry = 0;
    newNode = Shift(newNode, (holdSum + carry) % 10);
    carry = (holdSum + carry) / 10;
    temp = temp->next;
    while (temp != NULL)
    {
        holdSum = temp->data;
        newNode = Shift(newNode, (holdSum + carry) % 10);
        carry = (holdSum + carry) / 10;
        temp = temp->next;
    }
    if (carry > 0)
    {
        newNode = Shift(newNode, 1);
    }
    return newNode;
}