class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       vector<pair<int,double>>v[n];
        vector<double>dist(n,INT_MIN);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back({edges[i][1],succProb[i]});
            v[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        dist[start]=1;
        queue<int>q;
        q.push(start);
       while(!q.empty())
       {
           int t=q.front();
           q.pop();
           for(auto x:v[t])
           {
               if(dist[x.first]<x.second*dist[t])
               {
                   dist[x.first]=x.second*dist[t];
                   q.push(x.first);
                }
           }
    
       }
        if(dist[end]==INT_MIN) return 0;
        return dist[end];
        
    }
};
