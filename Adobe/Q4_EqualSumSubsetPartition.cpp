//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2!=0)
            return 0;
        sum=sum/2;
        bool t[n+1][sum+1];
        memset(t,false,sizeof(t));
        for(int i=0;i<n;i++)
        {
            t[i][0]=true;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=t[i-1][j-arr[i-1]]|t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        if(t[n][sum])
            return 1;
        else
            return 0;
    }
