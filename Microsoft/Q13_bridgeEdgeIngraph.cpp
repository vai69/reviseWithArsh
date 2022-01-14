//https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
//Given a Graph of V vertices and E edges and another edge(c - d), 
//the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
void dfs(int node,vector<bool>&vis,vector<int> adj[])
    {
        vis[node]=true;
        for(auto x:adj[node])
        {
            if(!vis[x])
                dfs(x,vis,adj);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int cn=0;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cn++;
                dfs(i,vis,adj);
            }
        }
        for(auto i=adj[c].begin();i!=adj[c].end();++i)
        {
            if(*i==d)
            {
                adj[c].erase(i);
                break;
            }
        }
        for(auto i=adj[d].begin();i!=adj[d].end();++i)
        {
            if(*i==c)
            {
                adj[d].erase(i);
                break;
            }
        }
        for(int i=0;i<V;i++) vis[i]=false;
        int ck=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                ck++;
            }
        }
        if(ck>cn)
            return 1;
        return 0;
    }
