// { Driver Code Starts
#include <bits/stdc++.h>
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

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);

    return new_Node;
}

Node *reverse(Node **r)
{
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node **head_ref, int new_data)
{
    /* allocate Node */
    struct Node *new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node)
{
    struct Node *temp;
    while (Node != NULL)
    {

        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

/* Multiply contents of two linked lists */
long long multiplyTwoLists(struct Node *, struct Node *);

// A utility function to print a linked list
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{

    int t, n, m, i, x;
    cin >> t;
    while (t--)
    {

        struct Node *first = NULL;
        struct Node *second = NULL;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x;
            push(&second, x);
        }

        reverse(&first);
        reverse(&second);
        long long res = multiplyTwoLists(first, second);

        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}
// } Driver Code Ends

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/

Node *reverse(Node *l)
{
    Node *curr = l;
    Node *Next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    l = prev;
    return l;
}

int length(Node *l)
{
    int len = 0;
    Node *temp = l;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
long long multiplyTwoLists(Node *l1, Node *l2)
{
    int len1 = length(l1);
    int len2 = length(l2);
    vector<int> result((length(l1) + length(l2)), 0);
    Node *new1 = reverse(l1);

    Node *temp2 = reverse(l2);
    Node *new2 = temp2;
    int i1 = 0, j1 = 0;
    for (int i = 0; i < len1; i++)
    {
        j1 = 0;
        int carry = 0;
        for (int j = 0; j < len2; j++)
        {
            int sum = result[i1 + j1] + new1->data * new2->data + carry;
            carry = sum / 10;
            result[i1 + j1] = sum % 10;
            j1++;
            new2 = new2->next;
        }
        if (carry > 0)
            result[i1 + j1] += carry;
        i1++;
        new1 = new1->next;
        new2 = temp2;
    }
    int i = result.size() - 1;
    while (result[i] == 0)
        i--;
    long long int temp = 0;
    while (i >= 0)
    {
        temp = temp * 10 + result[i];
        temp = temp % 1000000007;
        i--;
    }

    return temp;
}