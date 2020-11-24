#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int tem;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    while (st.size() > 0)
    {
        tem = st.top();
        cout << tem << " ";
        st.pop();
    }
}

//1 0 0 0
//1 1 0 1
//0 1 1 1