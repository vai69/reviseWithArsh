//https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/
class Solution{
  public:
    string nextPalin(string str) { 
      
        int n=str.length(),flg=0;
          if(n<=3) return "-1";
        string s="";
        for(int i=0;i<n/2;i++)
        {
            if(i!=0)
                if(str[i]>str[i-1]) flg=1;
            s+=str[i];
        }
        if(flg==0)
        {
            return "-1";
        }
        int i=s.length()-1;
        string k="";
        //cout<<s<<"\n";
        char ch;
        while(i>0)
        {
            k+=s[i];
            if(str[i]>str[i-1])
            {
                k+=s[i-1];
                ch=str[i-1];
                i--;
                break;
            }
            i--;
        }
        //cout<<k<<" "<<ch<<"\n";
        flg=0;
        sort(k.begin(),k.end());
         string k1="";
         for(int j=0;j<k.length();j++)
         {
             if(k[j]>ch&&flg==0)
             {
                 ch=k[j];
                 flg=1;
             }
             else
                k1+=k[j];
         }
            
        //cout<<s<<" "<<k1<<" "<<i<<"\n";
        string ans="";
        for(int j=0;j<i;j++) ans+=s[j];
        //cout<<ans<<" "<<k<<"\n";
        ans+=ch;
        ans+=k1;
        s=ans;
        if(n%2)
        {
            ans+=str[n/2];
        }
        reverse(s.begin(),s.end());
        ans+=s;
        return ans;

    }
};
