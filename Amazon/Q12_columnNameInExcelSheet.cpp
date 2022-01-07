//https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc.
// In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.

string colName (long long int n)
    {
        // your code here
        string ans="";
        while(n>0)
        {
            //cout<<n<<" "<<n%26<<"\n";
            int k=n%26;
            char ch='A'+(k-1);
            n=n/26;
            if(k==0) 
            {
                ans+='Z';
                n--;
            }
            else ans+=ch;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
