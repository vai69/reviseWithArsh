//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
//Given an unsorted array Arr of size N of positive integers.
//One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array.
//Find these two numbers.

vector<int>findTwoElement(int *arr, int n) {
        // code here
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]<0)
            {
                sum-=abs(arr[i]);
                ans.push_back(abs(arr[i]));
                break;
            }
            else
            {
               arr[abs(arr[i])-1]*=-1; 
            }
        }
        n=n+1;
        long long int x;
        if(n%2==0)
            x=(n/2)*(n-1);
        else
            x=((n-1)/2)*n;
        ans.push_back(x-sum);
        return ans;
        
        
    }
