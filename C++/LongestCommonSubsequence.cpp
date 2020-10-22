#include <iostream>
#include <algorithm>
using namespace std;
int longestCommonSequence(int num1, int num2, int arr1[], int arr2[])
{
    if (num1 == 0 || num2 == 0)
    {
        return 0;
    }
    else
    {
        int total[num1 + 1][num2 + 1] = {};
        total[0][0] = 0;
        int i, j;
        for (i = 1; i <= num1; i++)
        {
            for (j = 1; j <= num2; j++)
            {
                if (arr1[i - 1] == arr2[j - 1])

                {
                    total[i][j] = total[i - 1][j - 1] + 1;
                }
                else if (arr1[i - 1] != arr2[j - 1])
                {
                    total[i][j] = max(total[i][j - 1], total[i - 1][j]);
                }
            }
        }
        return total[num1][num2];
    }
    return 0;
}
int main()
{
    int num1;
    cin >> num1;
    int arr1[num1];
    for (int i = 0; i < num1; i++)
    {
        cin >> arr1[i];
    }
    int num2;
    cin >> num2;
    int arr2[num2];
    for (int i = 0; i < num2; i++)
    {
        cin >> arr2[i];
    }
    cout << longestCommonSequence(num1, num2, arr1, arr2) << endl;
}