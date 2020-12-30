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

void CombinationalSumUtilt(int sum, vector<int> &selectedNumbers, vector<vector<int>> &Allnumbers, int B, vector<int> &A)
{
    // for (int i = 0; i < selectedNumbers.size(); i++)
    // {
    //     cout << selectedNumbers[i] << ' ';
    // }

    if (sum == B)
    {
        if (arraySortedOrNot(selectedNumbers, selectedNumbers.size()))
        {
            Allnumbers.push_back(selectedNumbers);
            return;
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (isValid(A[i], sum, B))
        {
            selectedNumbers.push_back(A[i]);
            CombinationalSumUtilt(sum + A[i], selectedNumbers, Allnumbers, B, A);
            selectedNumbers.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> AllNumbers;
    vector<int> selectedNumbers;
    int sum = 0;
    CombinationalSumUtilt(sum, selectedNumbers, AllNumbers, B, A);
    return AllNumbers;
}