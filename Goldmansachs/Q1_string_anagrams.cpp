//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
//Given an array of strings, 
//return all groups of strings that are anagrams. 
//The groups must be created in order of their appearance in the original array.

 vector<vector<string> > Anagrams(vector<string>& v) {
        vector<pair<string,int>>pt; 
        vector<vector<string>>ans;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            string s=v[i];
            sort(s.begin(),s.end());
            pt.push_back({s,i});
        }
        sort(pt.begin(),pt.end());
        vector<string>tmp;
        tmp.push_back(v[pt[0].second]);
        for(int i=1;i<n;i++)
        {
            int j=pt[i].second;
            if(pt[i].first!=pt[i-1].first)
            {
                ans.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(v[j]);
        }
        if(tmp.size()!=0)
            ans.push_back(tmp);
        return ans;
    }
