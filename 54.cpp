// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	long int n,q,x,mr,mc,rc=0;
	cin>>n>>q;
    vector<int> r(n,0);
    vector<int> c(n,0);
	while(q--)
	{
	    string s;
	    cin>>s>>rc>>x;
	    if(s[0] == 'R')
	    {
	        r[rc-1] += x;
	    }
	    else
	    {
	        c[rc-1] += x;
	    }
	    
	}
	mr = *max_element(r.begin(),r.end());
	mc = *max_element(c.begin(),c.end());
	cout<<mr+mc<<endl;
	return 0;
}