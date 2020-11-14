class Solution
{
public:
    bool DpSol(int arr[], int sum, int N)
    {
        int dp[N + 1][sum + 1] = {};
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (j >= arr[i - 1])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1]] + arr[i - 1]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[N][sum] == sum)
        {
            return true;
        }
        return false;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 == 1)
        {
            return 0;
        }
        else
        {
            if (DpSol(arr, int(sum / 2), N))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
};