//Find max 10 numbers in a list having 10M entries.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	set<long long int>st;
	set<long long int>::iterator itr;
	for(long long int i=0;i<n;i++)
	{
		long long int a;
		cin>>a;
		if(st.size()<10)
		{
			st.insert(a);
		}
		else
		{
			itr=st.begin();
			if((*itr)<a)
			{
				st.erase(itr);
				st.insert(a);
			}
		}
	}
	for(itr=st.begin();itr!=st.end();itr++)
		cout<<(*itr)<<"\n";
}
