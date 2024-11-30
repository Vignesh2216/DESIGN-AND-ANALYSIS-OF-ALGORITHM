// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int sum(int x[], int a){
    if(a<0)
    return 0;
    return x[a]+sum(x,a-1);
}
int main()
{
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    cout<<"The sum of the elements in the array is "<<sum(x,n-1);
}