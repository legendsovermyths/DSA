#include <iostream>
using namespace std;
void Permutation(string st, string ans)
{
    if (st.length() == 0)
    {
        cout << ans << " ";
        return;
    }

    for (int i = 0; i < st.length(); i++)
    {
        char ch = st[i];
        string ros = st.substr(0, i) + st.substr(i + 1);
        cout << ans + ch << " ";
        Permutation(ros, ans + ch);
    }
}
int main()
{
    Permutation("abcd", "");
    return 0;
}