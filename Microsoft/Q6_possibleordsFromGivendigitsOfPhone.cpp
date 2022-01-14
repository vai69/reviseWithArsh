//https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
//Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ],
// the task is to list all words which are possible by pressing these numbers
class Solution
{
    public:
    vector<string>ans;
    int n;
    void solve(int dig[],int ind,string s)
    {
        if(ind==n)
        {
            ans.push_back(s);
            return;
        }
        int k=dig[ind];
        int j=3*(k-2);
        int lt=3;
        if(k==7||k==9) lt=4;
        if(k==8||k==9) j++;
        for(int i=0;i<lt;i++)
        {
            char ch='a'+j;
            solve(dig,ind+1,s+ch);
            j++;
        }
    }
    vector<string> possibleWords(int a[], int N) {
        ans.clear();
        n=N;
        if(n==0) return ans;
        solve(a,0,"");
        return ans;
    }
};
