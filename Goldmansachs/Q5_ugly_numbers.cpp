//https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

ull getNthUglyNo(int n) {
	    ull arr[n];
        arr[0]=1;
        int a=0,b=0,c=0;
        for(int i=1;i<n;i++)
        {
            arr[i]=min(arr[a]*2,min(arr[b]*3,arr[c]*5));
            if(arr[i]==arr[a]*2) a++;
            if(arr[i]==arr[b]*3) b++;
            if(arr[i]==arr[c]*5) c++;
        }
        return arr[n-1];
	}
