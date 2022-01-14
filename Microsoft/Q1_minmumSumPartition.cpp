//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
//Given an integer array arr of size N, the task is to divide it into two 
//sets S1 and S2 such that the absolute difference between their sums
//is minimum and find the minimum difference

int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    bool dp[n+1][sum/2+1];
	    for(int i=0;i<=n;i++) dp[i][0]=true;
	    for(int i=1;i<=sum/2;i++) dp[0][i]=false;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum/2;j++)
	        {
	            if(arr[i-1]<=j)
	            {
	                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
	            }
	            else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
	   // cout<<dp[1][20]<<" "<<dp[4][40]<<"\n";
	    int s=0;
	    for(int i=sum/2;i>=0;i--)
	    {
	       if(dp[n][i])
	       {
	           s=i;
	           break;
	       }
	    }
	    //cout<<s<<"\n";
	    return sum-(2*s);
	} 
