//https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1
class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=65&&s[i]<=90)
            {
                //cout<<s[i]<<"\n";
                if(i!=0)
                    ans+=" ";
                char ch=s[i]+32;
                ans+=ch;
            }
            else
                ans+=s[i];
        }
        return ans;
    }
};
