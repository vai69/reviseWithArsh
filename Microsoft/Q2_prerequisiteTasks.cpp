//https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
//There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites,
//for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]

class Solution {
public:
    bool dfs(vector<vector<int>>&v,int node,vector<bool>&vis,vector<bool>&path)
    {
        //cout<<node<<" "<<vis[node]<<"\n"
        path[node]=vis[node]=true;
        for(int i=0;i<v[node].size();i++)
        {
            if (path[v[node][i]] || dfs(v, v[node][i], vis, path))
                return true;
        }
        return path[node]=false;
    }
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    // Code here
	    vector<vector<int>>v(N);
	    for(int i=0;i<p.size();i++)
	    {
	        v[p[i].second].push_back(p[i].first);
	    }
	    vector<bool>vis(N,false);
	    for(int i=0;i<N;i++)
	    {
	        vector<bool>path(N,false);
	        
	        if(!vis[i]&&dfs(v,i,vis,path))
                return false;
                
	    }
	    return true;
	    
	}
};


