//https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
//N = 2
//Output: 
//1 10
vector<string> generate(int N)
{
	// Your code here
	vector<string>ans;
	for(int i=1;i<=N;i++)
	{
	    string s="";
	    int t=i;
	    while(t>0)
	    {
	        char ch=((t%2)+'0');
	        s=ch+s;
	        t=t/2;
	    }
	    ans.push_back(s);
	}
	return ans;
}
