//https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/
long long power(int N,int R)
    {
        
        long long res=1;
        
        if(R==0)
            return 1;
        long long int n=N;
        while(R>0){
            if(R%2)
            {
                res=res*n;
                R--;
            }
            res=res%mod;
            n*=n;
            n=n%mod;
            R/=2;
        }
        
        return (res%mod);
        
       //Your code here
        
    }
