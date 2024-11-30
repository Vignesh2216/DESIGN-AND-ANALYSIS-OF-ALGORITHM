// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x[n];
    for(int i=0;i<n;i++){
        int q=i;
        x[i]=a[i];
        if(i>0){
            for(int j=q-1;j>=0;j--){
                if(x[q]<x[j]){
                    swap(x[q],x[j]);
                    q--;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
}