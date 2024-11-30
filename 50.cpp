// You are using GCC
#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int t ; 
	cin>>t ;
	while(t--)
	{
	    int n ;
	    cin>>n ;
	    string s ;
	    cin>>s ;
	    int cnt = n/2+1 ;
	    int rem = n-cnt ;
	    vector<char>temp;
	    int ind = 0 ;
	    while(ind< n && rem>0)
	    {
	       temp.push_back('P') ;
         rem--;
        if(s[ind] == 'R')rem ++ ;
        
	        ind ++;
	    }
	    for(;ind<s.size();ind++){
	        if(s[ind] == 'R'){
	            temp.push_back('P');
	        }
	        else if(s[ind] == 'S'){
	            temp.push_back('R');
	        }
	        else{
	            temp.push_back('S');
	        }
	    }
	    for(auto it : temp)
	    {
	        cout<<it ;
	    }
     cout<<endl;
	}
	return 0;
}

