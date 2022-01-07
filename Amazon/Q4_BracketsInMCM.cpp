//https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/
//Input: 
//n = 5
//p[] = {1, 2, 3, 4, 5}
//Output: (((AB)C)D)

int br[30][30];
    string ans;
    void display(int i,int j,char& ch)
    {
        if(i>j) return;
        if(i==j)
        {
            ans+=ch++;
            return;
        }
        ans+='(';
        display(i,br[i][j],ch);
        display(br[i][j]+1,j,ch);
        ans+=')';
    }
    void mcm(int p[],int n)
    {
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]=0;
        
        for(int l=2;l<n;l++)
        {
            for(int i=1;i<n-l+1;i++)
            {
                int j=i+l-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                    if(q<dp[i][j])
                    {
                        br[i][j]=k;
                        dp[i][j]=q;
                    }
                }
            }
        }
    }
    string matrixChainOrder(int p[], int n){
        // code here
        mcm(p,n);
        ans="";
        char c='A';
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<br[i][j]<<" ";
        //     cout<<"\n";
        // }
        display(1,n-1,c);
        return ans;
    }
