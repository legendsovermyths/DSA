// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
bool isValid(int number, int sum, int B)
{
    return number + sum <= B;
}
bool arraySortedOrNot(vector<int> arr, int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (arr[n - 1] < arr[n - 2])
        return 0;
    return arraySortedOrNot(arr, n - 1);
}

void CombinationalSumUtilt(int sum, vector<int> &selectedNumbers, vector<vector<int>> &Allnumbers, int B, vector<int> &A, int i)
{
    // for (int i = 0; i < selectedNumbers.size(); i++)
    // {
    //     cout << selectedNumbers[i] << ' ';
    // }

    if (sum == B)
    {

        Allnumbers.push_back(selectedNumbers);
        return;
    }
    while (i < A.size())
    {
        if (isValid(A[i], sum, B))
        {
            selectedNumbers.push_back(A[i]);
            CombinationalSumUtilt(sum + A[i], selectedNumbers, Allnumbers, B, A, i);
            selectedNumbers.pop_back();
        }
        i++;
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> AllNumbers;
    vector<int> selectedNumbers;
    vector<int>::iterator ip;
    sort(A.begin(), A.end());
    ip = std::unique(A.begin(), A.begin() + A.size());
    A.resize(std::distance(A.begin(), ip));
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    int sum = 0;
    CombinationalSumUtilt(sum, selectedNumbers, AllNumbers, B, A, 0);
    return AllNumbers;
}

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        vector<vector<int>> result;
        result = combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
} // } Driver Code Ends