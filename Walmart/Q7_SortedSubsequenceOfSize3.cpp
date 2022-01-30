//https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int>p(N);
        vector<int>s(N);
        p[0]=arr[0];s[N-1]=arr[N-1];
        for(int i=1,j=N-2;i<N;i++,j--)
        {
            p[i]=min(arr[i-1],p[i-1]);
            s[j]=max(arr[j+1],s[j+1]);
        }
        vector<int>ans;
        for(int i=1;i<N-1;i++)
        {
            //cout<<p[i]<<" "<<arr[i]<<" "<<s[i]<<"\n";
            if(p[i]<arr[i]&&s[i]>arr[i])
            {
                
                ans.push_back(p[i]);
                ans.push_back(arr[i]);
                ans.push_back(s[i]);
                return ans;
            }
        }
        return ans;
    }
};
