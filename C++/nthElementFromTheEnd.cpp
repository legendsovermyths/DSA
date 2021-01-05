// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
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

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
} // } Driver Code Ends

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
Node *reverse(Node *head)
{
    std::cout << "sfkdh" << std::endl;
    Node *curr = head;
    Node *prev = NULL;
    Node *nexts = NULL;
    while (curr != NULL)
    {
        cout << "A";
        nexts = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexts;
    }
    head = prev;
    return head;
}
int getNthFromLast(Node *head, int n)
{
    head = reverse(head);
    Node *temp = head;
    int t = n - 1;
    while (t--)
    {
        cout << "D"
             << " ";
        temp = temp->next;
    }
    return temp->data;
}
