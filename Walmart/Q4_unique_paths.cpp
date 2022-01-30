//https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1
class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int dp[a][b];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<a;i++)
            dp[i][0]=1;
        for(int i=1;i<b;i++)
            dp[0][i]=1;
        for(int i=1;i<a;i++)
        {
            for(int j=1;j<b;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[a-1][b-1];
    }
};
