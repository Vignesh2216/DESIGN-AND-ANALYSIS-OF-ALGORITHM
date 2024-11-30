// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void worstcase(vector<int>& arr,int left,int right){
    if(right-left<=1)
    return;
    int  mid=(left+right)/2;
    vector<int>temp(arr.begin()+left,arr.begin()+right+1);
    for(int i=0;i<=mid-left;i++)
    {
        arr[left+i]=temp[i*2];
    }
    for(int i=0;i<right-mid;i++)
    {
        arr[left+mid-left+1+i]=temp[i*2+1];
    }
    worstcase(arr,left,mid);
    worstcase(arr,mid+1,right);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    worstcase(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}