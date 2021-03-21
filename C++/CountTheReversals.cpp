#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int count = s.length();
        if (count % 2 == 1)
        {
            cout << -1 << endl;
            break;
        }

        stack<char> st;
        st.push('s');
        for (int i = 0; i < count; i++)
        {
            if (s[i] == '{')
            {
                st.push(s[i]);
            }
            else if ((s[i] == '}') && (st.top() == '{'))
            {
                st.pop();
            }
            else if (s[i] == '}')
            {
                st.push('}');
            }
        }
        count = st.size();
        int closed = 0, open = 0;
        for (int i = 0; i < count - 1; i++)
        {
            if (st.top() == '}')
            {
                closed++;
                st.pop();
            }
            else if (st.top() == '{')
            {
                open++;
                st.pop();
            }
        }
        cout << closed << ' ' << open;
        int answer = 2 * min(closed, open);
        int remain = max(closed, open) - min(closed, open);
        remain = remain / 2;
        cout << remain + answer << endl;
    }
    return 0;
}