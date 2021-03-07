for (int i = 0; i <= int(sqrt(n)); i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }