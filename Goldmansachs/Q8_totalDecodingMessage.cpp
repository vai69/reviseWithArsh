//https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1
//Input: str = "123"
//Output: 3
//Explanation: "123" can be decoded as "ABC"(123),
//"LC"(12 3) and "AW"(1 23).

int CountWays(string str){
		    // Code here
		    int n=str.length();
		    int dp[n+1];
		    memset(dp,0,sizeof(dp));
		    dp[0]=1;dp[1]=1;
		    if(str[0]=='0')
		        return 0;
		    for(int i=2;i<=n;i++)
		    {
		            dp[i]=0;
		            if(str[i-1]>'0')
		                dp[i]=dp[i-1];
		            if((str[i-2]=='2'&&str[i-1]<'7')||(str[i-2]=='1'))
		                dp[i]=(dp[i]+dp[i-2])%1000000007;
		            
		    }
		    //cout<<"\n";
		    return dp[n];
		    
		}
