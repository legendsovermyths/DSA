// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
public:
    //Function to merge K sorted linked list.
    Node *Merge(Node *a, Node *b)
    {
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
        Node *res = NULL;
        if (a->data > b->data)
        {
            res = b;
            res->next = Merge(a, b->next);
        }
        else if (b->data >= a->data)
        {
            res = a;
            res->next = Merge(a->next, b);
        }
        return res;
    }

    Node *mergeKLists(Node *arr[], int K)
    {
        Node *temp = arr[0];
        for (int i = 1; i < K; i++)
        {
            temp = Merge(temp, arr[i]);
        }
        return temp;
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends