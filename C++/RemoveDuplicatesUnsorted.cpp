#include <unordered_map>
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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *removeDuplicates(Node *root);

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
Node *removeDuplicates(Node *head)
{

    Node *start = head;
    unordered_map<int, int> umap;
    while (start)
    {

        umap[start->data] = +1;
        start = start->next;
    }
    Node *curr = new Node(INT16_MAX);
    curr->next = head;
    while (curr && curr->next)
    {

        if (umap[curr->next->data] >= 1)
        {
            curr = curr->next;
            umap[curr->data] = 0;
        }
        else
        {
            curr->next = curr->next->next;
        }
    }
    return head;
}