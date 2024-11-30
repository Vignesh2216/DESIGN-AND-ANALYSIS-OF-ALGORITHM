// You are using GCC
#include<iostream>
using namespace std;
int part(int a[],int l,int h){
    int p = a[h];
    int i =l-1;
    for(int j=l;j<h;j++){
        if(a[j]<p){
            i++;
            int t = a[i];a[i]=a[j];a[j]=t;
        }
    }
    int t = a[i+1];a[i+1]=a[h];a[h]=t;
    return i+1;
}
void sort(int a[],int l,int h){
    if(l<h){
        int pi = part(a,l,h);
        sort(a,l,pi-1);
        sort(a,pi+1,h);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    sort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}