//https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
class Solution {
public:
    struct cmp{
        bool operator()(string const& a,string const& b)
        {
            if(a.length()!=b.length())
                return a.length()>b.length();
            return a>b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,cmp>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++)
        {
            if(pq.top().length()<nums[i].length()||(pq.top().length()==nums[i].length()&&pq.top()<nums[i]))
            {
                pq.pop();
                pq.push(nums[i]);
            }
            
        }
        return pq.top();
    }
};
