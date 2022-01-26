 //https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/
 int dp[501][501];
    int solve(vector<int>&a,int i,int j)
    {
        if(i>j) return 0;
        if(i==j) return a[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int b=solve(a,i+1,j-1);
        int c=solve(a,i+2,j);
        int d=solve(a,i,j-2);
        int ans=max(a[i]+min(b,c),a[j]+min(b,d));
        dp[i][j]=ans;
        return ans;
    }
    int maxCoins(vector<int>&A,int n)
    {
        memset(dp,-1,sizeof(dp));
	    return solve(A,0,n-1);
    }
