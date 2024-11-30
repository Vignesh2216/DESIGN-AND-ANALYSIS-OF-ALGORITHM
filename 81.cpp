// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p=n*n;
    int a[p];
    for(int i=0;i<p;i++){
        cin>>a[i];
    }
    for(int i=0;i<p-1;i++){
        for(int j=i+1;j<p;j++){
            if(a[i]>a[j])
            swap(a[i],a[j]);
        }
    }
    int x[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j]=a[i*n+j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
}