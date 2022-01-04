//https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
//Given an array of integers and a number k, 
//write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k
bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n%2) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]%k]++;
        }
        for(auto x:mp)
        {
            if(x.first==0)
            {
                if(x.second%2) return false;
            }
            else
            {
                if(x.second>0)
                {
                    if(mp[k-x.first]>=x.second)
                    {
                        x.second=0;
                        mp[k-x.first]-=x.second;
                    }
                    else
                        return false;
                }
                
            }
        }
        return true;
    }
