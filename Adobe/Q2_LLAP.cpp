//https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/
int lengthOfLongestAP(int A[], int n) {
        // code here
        
        vector<vector<int>>v(n,vector<int>(A[n-1]-A[0]+1,0));
        
        int len=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j];
                //cout<<i<<" "<<v[i][diff]<<" "<<diff<<" "<<v[j][diff]<<"\n";
                v[i][diff]=max(v[i][diff],v[j][diff]+1);
                
                len = max(len,v[i][diff]);
                
            }
        }
        
        return (len+1);
        
    }
