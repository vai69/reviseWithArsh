 //https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/
 //Stickler the thief wants to loot money from a society having n houses in a single line. 
// He is a weird person and follows a certain rule when looting the houses.
//  According to the rule, he will never loot two consecutive houses.
 int FindMaxSum(int arr[], int n)
    {
        int ans=0;
        int a=0,b=0,c=0;
        if(n==1)
            return arr[0];
        else if(n==2)
        {
            return max(arr[0],arr[1]);
        }
        else
        {
            ans=max(arr[0],arr[1]);
            for(int i=2;i<n;i++)
            {
                //cout<<a<<" "<<b<<" "<<c<<" "<<ans<<"\n";
                if(i==2)
                {
                    a=arr[0];
                    b=arr[1];
                    c=arr[0]+arr[i];
                    ans=max(ans,c);
                }
                else
                {
                    ans=max(ans,arr[i]+max(a,b));
                    int k=max(a,b);
                    a=b;
                    b=c;
                    c=arr[i]+k;
                }
            }
        }
        return ans;
    }
