//find number of squares in n*n chessboard
//consider n=4...then number of squares of 1*1=4*4=16
//then number of squares of 2*2=3*3=9
//then number of squares of 3*3=2*2=4
//then number of squares of 4*4=1*1=1

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<((n+1)*(2*n+1)*n)/6;
}
