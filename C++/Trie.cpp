#include <bits/stdc++.h>
using namespace std;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define loop(k, n) for (int k = 0; k < n; k++)
#define deb(x) cout << #x << "= " << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define Loop(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define ll long long
#define PI 3.1415926535897932384626
typedef vector<int> vi;
typedef vector<ll> vl;

class Trie
{
public:
    class Node
    {
    public:
        bool end;
        vector<Node *> nxt;
        Node()
        {
            for (int i = 0; i < 26; i++)
                nxt.push_back(NULL);
        }
    };
    Node *trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(string word)
    {
        int i = 0;
        Node *temp = trie;
        while (i < word.length())
        {
            if (temp->nxt[word[i] - 'a'] == NULL)
            {
                temp->nxt[word[i] - 'a'] = new Node();
                temp = temp->nxt[word[i] - 'a'];
                i++;
            }
            else
            {
                temp = temp->nxt[word[i] - 'a'];
                i++;
            }
        }
        temp->end = true;
    }
    bool search(string word)
    {
        int i = 0;
        Node *temp = trie;
        while (i < word.length())
        {
            if (temp->nxt[word[i] - 'a'] == NULL)
                return false;
            else
            {
                temp = temp->nxt[word[i] - 'a'];
                i++;
            }
        }
        return temp->end;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("anirudh");
    trie->insert("madhav");
    cout << trie->search("Rahul") << endl;
}