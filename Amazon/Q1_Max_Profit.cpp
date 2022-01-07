//https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
//In the stock market, a person buys a stock and sells it on some future date.
//Given the stock prices of N days in an array A[ ] and a positive integer K,
//find out the maximum profit a person can make in at-most K transactions. 
//A transaction is equivalent to (buying + selling) of a stock and new
//transaction can start only when the previous transaction has been completed.

int maxProfit(int k, int n, int A[]) {
        // code here
        int dp[k+1][n];
        for(int i=0;i<=k;i++)
            dp[i][0]=0;
        for(int i=0;i<n;i++)
            dp[0][i]=0;
            
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                int mx=INT_MIN;
                for(int p=0;p<j;p++)
                {
                    mx=max(mx,A[j]-A[p]+dp[i-1][p]);
                }
                dp[i][j]=max(dp[i][j-1],mx);
            }
        }
        return dp[k][n-1];
        
    }
