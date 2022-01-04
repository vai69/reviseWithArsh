//https://leetcode.com/problems/minimum-size-subarray-sum/
//Given an array of positive integers nums and a positive integer target,
// return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
// of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,s=0;
        int n=nums.size();
        int ans=INT_MAX;
        int j=0;
        while(i<n)
        {
            
            s+=nums[i];
            i++;
            
            while(s>target)
            {
                if(s-nums[j]<target) break;
                s-=nums[j];
                j++;
            }
            if(s>=target)
            {
                ans=min(ans,i-j);
            }
            cout<<i<<" "<<j<<" ";
            cout<<i-j<<"\n";
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
