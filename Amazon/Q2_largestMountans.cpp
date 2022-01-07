//https://leetcode.com/problems/longest-mountain-in-array/
//You may recall that an array arr is a mountain array if and only if:
//	arr.length >= 3
//	There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array arr, return the length of the longest subarray,
//which is a mountain. Return 0 if there is no mountain subarray.

int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        int pre[n];
        int suf[n];
        pre[0]=0;
        suf[n-1]=0;
        for(int i=1,j=n-2;i<n;i++,j--)
        {
            pre[i]=0;suf[j]=0;
            if(arr[i]>arr[i-1])
                pre[i]+=pre[i-1]+1;
            if(arr[j]>arr[j+1])
                suf[j]+=suf[j+1]+1;
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(pre[i]!=0&&suf[i]!=0)
                ans=max(ans,pre[i]+suf[i]+1);
        }
        return ans;
    }
    
//can be done in O(1) space using only two variables
// for (int i = 1; i < A.size(); ++i) {
//            if (down && A[i - 1] < A[i] || A[i - 1] == A[i]) up = down = 0;
//            up += A[i - 1] < A[i];
//            down += A[i - 1] > A[i];
//            if (up && down) res = max(res, up + down + 1);
//        }
