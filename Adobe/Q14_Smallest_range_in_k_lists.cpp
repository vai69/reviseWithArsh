//https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        
        int m=-1;
        
        for(int i=0;i<k;i++){
            pq.push({KSortedArray[i][0],{i,0}});
            m=max(m,KSortedArray[i][0]);
        }
        
        int ans=INT_MAX;
        int r1=KSortedArray[0][0],r2=KSortedArray[0][0];
        
        while(!pq.empty()){
            pair<int, pair<int, int>>p=pq.top();
            pq.pop();
        
            
            if((m-p.first)<ans){
                ans=m-p.first;
                r1=p.first;
                r2=m;
            }
            
            if(p.second.second<(n-1)){
                pq.push({KSortedArray[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
                m=max(m,KSortedArray[p.second.first][p.second.second+1]);
            }
            else
                break;
            
        }
        
        pair<int,int>res;
        res.first=r1;
        res.second=r2;
        
        return res;
        
          //code here
    }
};
