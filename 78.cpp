// You are using GCC
#include<iostream>
using namespace std;
void msort(int a[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int la[n1];int ra[n2];
    for(int i=0;i<n1;i++)
        la[i]=a[l+i];
    
    for(int i=0;i<n2;i++){
        ra[i]=a[m+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(la[i]<=ra[j]){
            a[k]=la[i];
            i++;
        }else{
            a[k]=ra[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=la[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=ra[j];
        j++;
        k++;
    }
}
void sort(int a[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        msort(a,l,m,r);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    sort(a,0,n-1);
    
    for(int num: a){
        cout<<num<<" ";
    }
}