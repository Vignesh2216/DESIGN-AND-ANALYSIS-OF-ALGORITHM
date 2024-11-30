// You are using GCC
#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int la[n1];int ra[n2];
    for(int i=0;i<n1;i++)
        la[i]=a[l+i];
        
    for(int i=0;i<n2;i++)
        ra[i]=a[m+1+i];
    
    int i=0;int j=0;int k=l;
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
void mergeSort(int a[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    mergeSort(a,0,n-1);
    
    for(int num: a){
        cout<<num<<" ";
    }
}