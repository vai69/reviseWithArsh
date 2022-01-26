//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int>ans;
        long long int j=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            while(sum>s)
            {
                sum-=arr[j];
                j++;
            }
            if(sum==s)
            {
                ans.push_back(j+1);
                ans.push_back(i+1);
                return ans;
            }
        }
        ans.push_back(-1);
        return ans;
    }
