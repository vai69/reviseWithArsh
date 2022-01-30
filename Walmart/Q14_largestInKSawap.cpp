//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/
class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans;
    void swap(char *a,char *b)
    {
        char t=*a;
        *a=*b;
        *b=t;
    }
    void solve(string str,int k,int ind)
    {
        if(k==0)
            return;
        int n=str.length();
           char ch=str[ind];
           for(int i=ind+1;i<n;i++)
           {
               if(ch<str[i])
                    ch=str[i];
           }
           if(ch!=str[ind])
                k--;
            for(int i=n-1;i>=ind;i--)
            {
                   if(ch==str[i])
                   {
                       swap(&str[ind],&str[i]);
                        if (str.compare(ans) > 0)
                            ans = str;
                        solve(str,k,ind+1);
                        swap(&str[ind],&str[i]);
                   }
            }
          
    }
    string findMaximumNum(string str, int k)
    {
        ans="";
        solve(str,k,0);
       return ans;
    }
};
