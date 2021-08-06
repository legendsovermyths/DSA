// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
public:
    class node
    {
    public:
        int key;
        int value;
        node *next = NULL;
        node *prev = NULL;
        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    map<int, node *> m;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node *temp)
    {
        node *dummy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dummy;
        dummy->prev = temp;
    }
    void deleteNode(node *temp)
    {
        node *deleteNxt = temp->next;
        node *deleteprv = temp->prev;
        deleteprv->next = deleteNxt;
        deleteNxt->prev = deleteprv;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *res = m[key];
            m.erase(key);
            int val = res->value;
            deleteNode(res);
            addNode(res);
            m[key] = head->next;
            return val;
        }
        else
        {
            return -1;
        }
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *res = m[key];
            m.erase(key);
            deleteNode(res);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node *ans = new node(key, value);
        addNode(ans);
        m[key] = head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends