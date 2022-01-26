//https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/
vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int ans=0;
        string as="";
        for(auto x:mp)
        {
            if(x.second>ans)
            {
                ans=x.second;
                as=x.first;
            }
            else if(x.second==ans&&as>x.first)
            {
                as=x.first;
            }
            
        }
        
        vector<string>v={as,to_string(ans)};
        return v;
    }
