//https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
int numOfWays(int n, int x)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            long long int y = pow(i, x);
            for (int j = n; j >= i; j--)
            {

                if (j >= y)
                {
                    dp[j] = (dp[j] + dp[j - y]) % MOD;
                }
            }
        }
        return dp[n];
    }
