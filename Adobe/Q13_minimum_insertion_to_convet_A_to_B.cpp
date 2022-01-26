//https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/
class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        
        vector<int>lis;
        
       set<int>st;
       for(int i=0;i<M;i++)
            st.insert(B[i]);
            
        int cnt=0;
        
        for(int i=0;i<N;i++){
            if(st.find(A[i])!=st.end()){
                auto it=lower_bound(lis.begin(),lis.end(),A[i]);
                if(it==lis.end())
                    lis.push_back(A[i]);
                else
                    *it=A[i];
            }
        }
        
        return (N-lis.size()+M-lis.size());
            
    }
};
