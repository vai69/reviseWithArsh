//https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/
//Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
//Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
class Solution
{
    public:
    int r,c;
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& a,int &ans,int i,int j)
    {
        a[i][j]=1;
        if(j<c-1)
        {
            if(grid[i][j+1]==1&&a[i][j+1]==0)
           { ans++;
           //cout<<i<<" "<<j+1<<"\n";
            dfs(grid,a,ans,i,j+1);}
        }
        if(i<r-1)
        {
            if(grid[i+1][j]==1&&a[i+1][j]==0)
            {ans++;
            dfs(grid,a,ans,i+1,j);}
        }
        if(j>0)
        {
            if(grid[i][j-1]==1&&a[i][j-1]==0)
            {ans++;
            dfs(grid,a,ans,i,j-1);}
        }
        if(i>0)
        {
            if(grid[i-1][j]==1&&a[i-1][j]==0)
            {ans++;
            dfs(grid,a,ans,i-1,j);}
        }
        if(j>0&&i>0)
        {
            if(grid[i-1][j-1]==1&&a[i-1][j-1]==0)
            {ans++;
            dfs(grid,a,ans,i-1,j-1);}
        }
        if(j<c-1&&i<r-1)
        {
            if(grid[i+1][j+1]==1&&a[i+1][j+1]==0)
            {ans++;
            dfs(grid,a,ans,i+1,j+1);}
        }
        if(j>0&&i<r-1)
        {
            if(grid[i+1][j-1]==1&&a[i+1][j-1]==0)
           { ans++;
            dfs(grid,a,ans,i+1,j-1);}
        }
        if(j<c-1&&i>0)
        {
            if(grid[i-1][j+1]==1&&a[i-1][j+1]==0)
            {ans++;
            dfs(grid,a,ans,i-1,j+1);}
        }
        
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        r=grid.size();
        c=grid[0].size();
        vector<vector<int>>a(r);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                a[i].push_back(0);
            }
        }
        
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int mx=0;
                if(a[i][j]==0&&grid[i][j]==1)
                {
                    mx=1;
                    dfs(grid,a,mx,i,j);
                }
                ans=max(ans,mx);
            }
        }
        return ans;
    }
};
