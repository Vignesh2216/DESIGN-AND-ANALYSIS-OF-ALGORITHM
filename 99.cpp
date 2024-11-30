// You are using GCC
#include<iostream>
#include<algorithm>
using namespace std;
int sr(int i,int n,int a[],int x){
    int z=(i+n)/2;
    if(i>n){
        return 0;
    }
    if(a[z]==x)
    return 1;
    else if(a[z]<x){
        sr(z+1,n,a,x);
    }
    else if(a[z]>x){
        sr(i,z-1,a,x);
    }
}
int main(){
    int n,i=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    sort(a,a+n);
    if(sr(i,n,a,x)==1)
    cout<<"Key found";
    else
    cout<<"Key not found";
}