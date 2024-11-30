// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(j-i>k)
            break;
            if(arr[j]<arr[mini])
            mini=j;
        }
        for(int j=mini;j>i;j--){
            swap(arr[j],arr[j-1]);
            k--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}