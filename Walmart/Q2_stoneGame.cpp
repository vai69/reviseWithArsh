//https://leetcode.com/problems/stone-game
class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& arr,int i,int j)
    {
        if(i==j)
            return arr[i];
        if(i>j)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1)),arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1)));
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,piles.size()-1);
    }
};
