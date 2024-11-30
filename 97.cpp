// You are using GCC
#include<iostream>
#include<algorithm>
using namespace std;
bool ck(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])
        return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    sort(a,a+n);
    if(ck(a,b,n)){
        cout<<"The array is sorted.";
    }
    else{
        cout<<"The array is not sorted.";
    }
}