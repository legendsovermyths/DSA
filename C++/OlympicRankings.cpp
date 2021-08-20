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

class Country
{
public:
    int gold;
    int silver;
    int bronze;
    Country(int g, int s, int b)
    {
        gold = g;
        silver = s;
        bronze = b;
    }
};
bool compare(Country *c1, Country *c2)
{
    return c1->gold + c1->silver + c1->bronze > c2->gold + c2->silver + c2->bronze;
    // if (c1->gold != c2->gold)
    //     return c1->gold > c2->gold;
    // if (c1->silver != c2->silver)
    //     return c1->silver > c2->silver;
    // else
    //     return c1->bronze > c2->bronze;
}
int main()
{
    w(t)
    {

        int x, y, z;
        cin >> x >> y >> z;
        Country *c1 = new Country(x, y, z);
        int a, b, c;
        cin >> a >> b >> c;
        Country *c2 = new Country(a, b, c);
        int answer = compare(c1, c2) ? 1 : 2;
        cout << answer << endl;
    }
}