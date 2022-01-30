//https://leetcode.com/problems/divide-two-integers/submissions/
class Solution {
public:
   int divide(long div, long dis) {
       if(div==INT_MIN&&dis==-1)
           return INT_MAX;
       long a=abs(div);
       long b=abs(dis);
       long ans;
       double k=(double)log(a)-(double)log(b);
       if((div>0&&dis>0)||(div<0&&dis<0))
           ans=exp(k);
       else
            ans=-exp(k);
       
       
        if(ans>INT_MAX)
            ans=INT_MAX;
        if(ans<INT_MIN)
            ans=INT_MIN;
        cout<<ans;
        return ans;
    }
};
