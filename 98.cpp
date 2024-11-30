// You are using GCC
#include<iostream>
using namespace std;
int re(int n,int a[],int x){
    for(int i=0;i<n;i++){
        if(a[i]==x)
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    if(re(n,a,x)==1){
        cout<<x<<" is present";
    }
    else{
        cout<<x<<" is not present";
    }
}