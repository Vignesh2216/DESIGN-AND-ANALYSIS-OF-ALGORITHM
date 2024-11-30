// You are using GCC
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int q;
    cin>>q;
    int n=q*q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b[q][q];
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            b[i][j]=a[i*q+j];
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}