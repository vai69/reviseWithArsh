//https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/
class Solution
{
  public:
  int mod=1000000007;
   int kvowelwords(int N, int K) {
        // Write Your Code here
        vector<vector<long long>> dp(N+1, vector<long long>(K+1));
        
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= K; j++) {
                if(i == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i-1][K] * 21 % mod;
                    if(j > 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] * 5 % mod) % mod;
                }
            }
        }
        return dp[N][K];
    }
};

