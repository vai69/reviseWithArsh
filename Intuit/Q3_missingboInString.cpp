//https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/
void dfs(const string &str,int &size,int i,vector<long>&ans){
    if(i>=str.length())
        return;
    
    if((i+size)>str.length())
        return;
        
    string p=str.substr(i,size);
    if(ans.size()==0)
        ans.push_back(stol(p));
    else
    {
        long r=ans.back(),q=stol(p);
        if(r==(q-1) || r==(q-2))
            ans.push_back(q);
        else
        {
            if((i+size)<str.length()){
                p.push_back(str[i+size]);
                q=stol(p);
                if(r==(q-1) || r==(q-2))
                    ans.push_back(q);
                else
                    return;
                size++;
            }
            else
                return;
        }
        
        
    }
    dfs(str,size,i+size,ans);
        
}




int missingNumber(const string& str)
{
    
    for(int i=1;i<=6 && i<=str.length();i++){
        
        vector<long>ans;
        dfs(str,i,0,ans);
        
        int cnt=0;
        for(int j=0;j<(ans.size()-1);j++){
            if((ans[j+1]-ans[j])==2)
                cnt++;
        }
        
        if(cnt==1){
            for(int j=0;j<(ans.size()-1);j++){
                if((ans[j+1]-ans[j])==2)
                    return (ans[j]+1);
            }
        }
        
    }
    
    return -1;
    
    
    // Code here
}
