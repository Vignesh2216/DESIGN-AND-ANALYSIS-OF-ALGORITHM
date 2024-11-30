// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    int q[x];
    for(int i=0;i<x;i++){
        cin>>q[i];
    }
    int y;
    cin>>y;
    int w[y];
    for(int i=0;i<y;i++){
        cin>>w[i];
    }
    int p=(x+y);
    int v[p];
    for(int i=0;i<x;i++){
        v[i]=q[i];
    }
    for(int i=x,j=0;i<p;i++,j++){
        v[i]=w[j];
    }
    for(int i=0;i<p-1;i++){
        for(int j=i+1;j<p;j++){
            if(v[i]>v[j]){
                swap(v[i],v[j]);
            }
        }
    }
    for(int i=0;i<p;i++){
        cout<<v[i]<<" ";
    }
}