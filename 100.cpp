// You are using GCC
#include<iostream>
using namespace std;
int src(int i,int n,int a[],int x){
    int z=(i+n)/2;
    if(i>n)
    return -1;
    if(a[z]==x)
    return z;
    else if(a[z]<x)
    src(z+1,n,a,x);
    else if(a[z]>x)
    src(i,z-1,a,x);
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
    if(src(i,n,a,x)==-1){
        cout<<"NO OCCURRENCES";
    }
    else{
        cout<<src(i,n,a,x);
    }
}