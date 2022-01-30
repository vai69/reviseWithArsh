//https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1
class Solution{
public:
    int height(int N){
        int a = sqrt(2*N);
        if(N < (a*(a + 1))/2)
            a--;
        return a;
    }
};
