bool isValid(vector<vector<int>> &ans, int j, int div)
    {
        int sum = 0;
        for (int k = 0; k < ans[j].size(); k++)
        {
            sum += ans[j][k];
            if (sum > div)
                return false;
        }
        return true;
    }
    void SolutionUtil(int i, vector<vector<int>> &ans, int n, int k, int div, int a[], bool &UltChecker)
    {
        if (i == n)
        {
            int checker = true;
            int sum = 0;
            for (int t = 0; t < k; t++)
            {
                for (int y = 0; y < ans[t].size(); y++)
                {
                    sum += ans[t][y];
                }
                if (sum != div)
                {
                    checker = false;
                    break;
                }
                sum = 0;
            }
            if (checker)
            {
                // for (int t = 0; t < k; t++)
                // {
                //     for (int y = 0; y < ans[t].size(); y++)
                //     {
                //         cout << ans[t][y] << " ";
                //     }
                //     cout << endl;
                // }
                UltChecker = true;
            }
            return;
        }
        for (int j = 0; j < k; j++)
        {
            if (isValid(ans, j, div) && !UltChecker)
            {
                ans[j].push_back(a[i]);
                SolutionUtil(i + 1, ans, n, k, div, a, UltChecker);
                ans[j].pop_back();
            }
        }
    }

    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        if (sum % k != 0)
            return 0;
        int div = sum / k;
        vector<vector<int>> ans(k);
        bool UltChecker = false;
        SolutionUtil(0, ans, n, k, div, a, UltChecker);
        return UltChecker;
    }