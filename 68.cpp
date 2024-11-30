// You are using GCC std=c++11
#include<bits/stdc++.h>
using namespace std; 
void Pairs(vector<vector<int>>arr,int row) 
{ 
	unordered_map<int,int>hM; 
	int s=0;
    for (int i=0;i<row;i++) 
	{ 
		int first=arr[i][0]; 
		int sec=arr[i][1]; 
		if(hM.find(sec)!=hM.end()&&hM[sec]==first) 
		{
		    cout<<"("<<sec<<", "<<first<<")"<<endl; 
			s=1;
		}
        else 
			hM[first]=sec; 
	} 
	if(s==0)
	{
	    cout<<"No such pairs";
	}
} 

int main() 
{ 
    int n,i;
    cin>>n;
    vector<vector<int> > arr(n,vector<int>(2, 0));
	for(i=0;i<n;i++)
	{
	    for(int j = 0;j<2;j++)
	    {
	        cin>>arr[i][j];
	    }
	}
	Pairs(arr, n); 
} 