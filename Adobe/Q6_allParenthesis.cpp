//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/
class Solution
{
    public:
    vector<string>ans;
    void solve(int n,string s,int op,int cl)
    {
        if(op==cl&&op==n)
        {
            ans.push_back(s);
            return;
        }
        if(op<n)
            solve(n,s+'(',op+1,cl);
        if(op>cl)
            solve(n,s+')',op,cl+1);
    }
    vector<string> AllParenthesis(int n) 
    {
        solve(n,"",0,0);
        return ans;
    }
};
