//https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
//Given a pattern containing only I's and D's. I for increasing and D for decreasing.
//Devise an algorithm to print the minimum number following that pattern.
//Digits from 1-9 and digits can't repeat.
//Input:
//IIDDD
//Output:
//126543

string printMinNumberForPattern(string s){
        // code here 
        string ans="";
         int mx=0,lt=0;
         for(int i=0;i<s.length();i++)
         {
             if(s[i]=='I')
             {
                int d=0,j=i+1;
                while(j<s.length()&&s[j]=='D')
                {
                    j++;
                    d++;
                }
                if(i==0)
                {
                    mx=d+2;
                    lt++;
                    ans+=to_string(lt);
                    ans+=to_string(mx);
                    lt=mx;
                }
                else
                {
                   mx+=d+1;
                   lt=mx;
                   ans+=to_string(lt);
                }
                for (int k=0; k<d; k++)
                {
                    --lt;
                    ans+=to_string(lt);
                    i++;
                }
             }
             else
             {
                 if(i==0)
                 {
                    int d=0,j=i+1;
                    while(j<s.length()&&s[j]=='D')
                    {
                        j++;
                        d++;
                    } 
                    mx=d+2;
                    ans+=to_string(mx);
                    ans+=to_string(mx-1);
                    lt=mx-1;
                 }
                 else
                {
                    lt--;
                    ans+=to_string(lt);
                }
                 
             }
             //cout<<ans;
         }
         return ans;
    }
