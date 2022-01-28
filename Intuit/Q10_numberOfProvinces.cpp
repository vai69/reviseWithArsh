//https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        vector<int> vis(n,0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        queue<int> q;
        int count = 0;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]){
                count++;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto x : adj[node]) {
                        if(!vis[x]){
                            q.push(x);
                            vis[x] = 1;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
