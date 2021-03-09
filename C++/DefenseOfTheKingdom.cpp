#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        vector<int> vec_x;
        vector<int> vec_y;
        vec_x.push_back(0);
        vec_x.push_back(w + 1);
        vec_y.push_back(0);
        vec_y.push_back(h + 1);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            vec_x.push_back(x);
            vec_y.push_back(y);
        }
        int difference_x = -1, difference_y = -1;
        sort(vec_x.begin(), vec_x.end());
        sort(vec_y.begin(), vec_y.end());
        for (int i = 0; i < vec_x.size() - 1; i++)
        {
            int temp_dif = vec_x[i + 1] - vec_x[i];
            if (temp_dif > difference_x)
            {
                difference_x = temp_dif;
            }
        }
        for (int i = 0; i < vec_y.size() - 1; i++)
        {
            int temp_dif = vec_y[i + 1] - vec_y[i];
            if (temp_dif > difference_y)
            {
                difference_y = temp_dif;
            }
        }
        cout << (difference_x - 1) * (difference_y - 1) << endl;
    }

    return 0;
}