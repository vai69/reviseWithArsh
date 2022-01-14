//https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
//Given a sorted dictionary of an alien language having N words and
// k starting alphabets of standard dictionary. 
// Find the order of characters in the alien language.
//N = 5, K = 4
//dict = {"baa","abcd","abca","cab","cad"}
//Output:'b', 'd', 'a', 'c'
class Solution{
    public:
    void dfs(vector<vector<int>>gd,vector<bool>&vis,stack<int>&st,int node)
    {
        vis[node]=true;
        for(auto x:gd[node])
        {
            if(!vis[x])
                dfs(gd,vis,st,x);
        }
        st.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>gd(K);
        for(int i=0;i<N-1;i++)
        {
            int j=0;
            string s=dict[i],t=dict[i+1];
            while(s[j]==t[j]&&j<s.length()&&j<t.length())
                j++;
            //cout<<s[j]<<" "<<t[j]<<"\n";
            if(j!=s.length()&&j!=t.length())
                gd[s[j]-'a'].push_back(t[j]-'a');
        }
        vector<bool>vis(K,false);
        stack<int>st;
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
              dfs(gd,vis,st,i);
        }
          
        string ans="";
        while(!st.empty())
        {
            char c=97+st.top();
            st.pop();
            ans+=c;
        }
        //cout<<ans<<"\n";
        return ans;
    }
};

