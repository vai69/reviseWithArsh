//https://leetcode.com/problems/find-in-mountain-array/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length();
        int left = 0, right = n-1, high, mid, val, preVal, postVal;
		
        while(left<=right){
            high = (left+right)/2;
            val = m.get(high);
            preVal = m.get(high-1);
            postVal = m.get(high+1);
            if(val > preVal && val > postVal) break;
            else if(val < postVal) left = high;
            else right = high;
        }
        
        left = 0, right = high;
        while(left <= right){
            mid = (left+right)/2;
            val = m.get(mid);
            if(val == target) return mid;
            else if(val < target) left = mid+1;
            else right = mid-1;
        }
        
        left = high, right = n-1;
        while(left <= right){
            mid = (left+right)/2;
            val = m.get(mid);
            if(val == target) return mid;
            else if(val > target) left = mid+1;
            else right = mid-1;
        }    
        
        return -1;
    }
};
