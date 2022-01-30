//https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0,n=colors.length();
        int c=1;
        for(int i=1;i<n;i++)
        {
            if(colors[i]!=colors[i-1]||i==n-1)
            {
               // cout<<c<<" "<<i<<"\n";
                if(colors[i]==colors[i-1]) c++;
                if(colors[i-1]=='A')
                {
                    a+=max(0,c-2);
                }
                else
                {
                    b+=max(0,c-2);
                }
                c=0;
            }
            c++;
        }
        //cout<<a<<" "<<b;
        if(a==b||b>a) return false;
        return true;
    }
};
