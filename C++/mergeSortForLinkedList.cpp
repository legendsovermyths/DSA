// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    //Function to sort the given linked list using Merge Sort.

    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = NULL;

        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        /* Pick either a or b, and recur */
        if (a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return (result);
    }

    void Split(Node *source,
               Node **frontRef, Node **backRef)
    {
        Node *fast;
        Node *slow;
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two 
    at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

    void mergeSort2(Node **head)
    {
        Node *head2 = *head;
        Node *a;
        Node *b;
        if (head2 == NULL || head2->next == NULL)
            return;
        Split(head2, &a, &b);
        mergeSort2(&a);
        mergeSort2(&b);
        *head = SortedMerge(a, b);
    }
    Node *mergeSort(Node *head)
    {
        mergeSort2(&head);
        return head;
    }
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends