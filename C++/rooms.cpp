#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string staircases;
        cin >> staircases;
        vector<int> staircase_indexes;
        for (int i = 1; i <= staircases.length(); i++)
        {
            if (staircases[i - 1] == '1')
            {
                if (i <= int(n / 2))
                {
                    staircase_indexes.push_back(n - i + 1);
                }
                else
                {
                    staircase_indexes.push_back(i);
                }
            }
        }
        if (staircase_indexes.empty() == true)
        {
            cout << n << endl;
        }
        else
        {
            int staircase_to_be_considered = *max_element(staircase_indexes.begin(), staircase_indexes.end());
            cout << (2 * staircase_to_be_considered) << endl;
        }
    }
}