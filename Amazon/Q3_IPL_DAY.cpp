//https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1
//N = 9, K = 3
//arr[] = 1 2 3 1 4 5 2 3 6
//Output: 
//3 3 4 5 5 5 6 
vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int>ans;
        deque<int>q;
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            while(!q.empty()&&arr[q.back()]<=arr[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k)
            {
                while(q.front()<=i-k)
                    q.pop_front();
            }
            if(i>=k-1)
                ans.push_back(arr[q.front()]);
        }
        return ans;
    }
