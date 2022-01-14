 //https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
// then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
 
 vector <int> calculateSpan(int price[], int n)
    {
        stack<int>s;
        vector<int>ans(n,1);
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(!s.empty()&&price[s.top()]<=price[i])
            {
                s.pop();
            }
            ans[i]=(s.empty() ? i+1 : i-s.top());
            s.push(i);
        }
        return ans;
    }
