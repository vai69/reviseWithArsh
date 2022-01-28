//https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int start = *max_element(nums.begin(),nums.end());
        int end = 0;
        for(int i=0;i<n;i++)
            end+=nums[i];
        while(start<end)
        {
            int p = 1;
            int mid = start + (end-start)/2;
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
                if(sum>mid)
                {
                    p++;
                    sum = nums[i];
                }
            }
            if(p<=m)
                end = mid;
            else
                start = mid+1;
        }
            return start;
        
    }
};
