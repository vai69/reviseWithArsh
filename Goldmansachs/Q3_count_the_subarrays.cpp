//https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/


int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int res=0;
        long long int p=1;
        for(int st=0,ed=0;ed<n;ed++)
        {
            p*=a[ed];
            while(st<ed&&p>=k)
            {
                p=p/a[st++];
            }
            if(p<k)
            {
                res+=ed-st+1;
            }
        }
        return res;
    }
    
