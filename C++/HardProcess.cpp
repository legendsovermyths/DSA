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

void Solution(vector<int> arr, int n, int k)
{
    int left = 0, right = 0;
    int countZeros = 0;
    while (countZeros < k && right < n)
    {

        if (arr[right] == 0)
        {
            countZeros++;
        }
        right++;
    }
    if (arr[right] == 0)
        right--;
    if (right == n)
    {
        cout << n << endl;
        loop(i, n) cout << 1 << " ";
        return;
    }
    int answer = right - left + 1;
    int answerR = right;
    int answerl = left;
    while (right < n)
    {
        if (answer < right - left + 1)
        {
            answer = right - left + 1;
            answerR = right;
            answerl = left;
        }
        right++;
        if (right < n && arr[right] == 0)
        {
            if (arr[left] == 0)
                left++;
            else
            {
                while (arr[left] != 0 && left < right)
                    left++;
                left++;
            }
        }
    }
    cout << answer << endl;
    loop(i, n)
    {
        if (i < answerl || i > answerR)
            cout << arr[i] << " ";
        else
            cout << 1 << ' ';
    }
    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n, 0);
    loop(i, n) cin >> vec[i];
    Solution(vec, n, k);
}