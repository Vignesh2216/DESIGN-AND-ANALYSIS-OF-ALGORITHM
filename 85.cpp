// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int z=n*n;
    int a[z];
    for(int i=0;i<z;i++){
        cin>>a[i];
    }
    for(int i=0;i<z-1;i++){
        for(int j=i+1;j<z;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    int v[n][n];
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        v[i][j]=a[i*n+j];
    }
    }
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
    }
}