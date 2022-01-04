//https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
//if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6?
string encode(string src)
{     
    string ans="";
    int t=1;
    for(int i=1;i<src.length();i++)
    {
        //cout<<i<<" "<<t<<"\n";
        if(src[i]!=src[i-1])
        {
            ans+=src[i-1];
            ans+=to_string(t);
            t=0;
        }
        t++;
    }
    ans+=src[src.length()-1];
    ans+=to_string(t);
    return ans;
}
