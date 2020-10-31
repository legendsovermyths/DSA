#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Maximize(int arrOfNumbers[], int numberToBeMade)
{
    int dpValues[4][numberToBeMade + 1];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= numberToBeMade; j++)
        {
            if (i == 0 || j == 0)
            {
                dpValues[i][j] = 0;
            }
            else if (j >= arrOfNumbers[i - 1] && (dpValues[i][j - arrOfNumbers[i - 1]] != 0 || j % arrOfNumbers[i - 1] == 0))
            {
                dpValues[i][j] = max(dpValues[i - 1][j], dpValues[i][j - arrOfNumbers[i - 1]] + 1);
            }
            else
            {
                dpValues[i][j] = dpValues[i - 1][j];
            }
        }
    }
    for (int s = 1; s < 4; s++)
    {
        for (int i = 1; i <= numberToBeMade; i++)
        {
            cout << dpValues[s][i] << " ";
        }
        cout << "\n";
    }
    return dpValues[3][numberToBeMade];
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int arr[3];
        int numberToBeMade;
        cin >> numberToBeMade;
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        cout << Maximize(arr, numberToBeMade) << endl;
    }
}
