// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int c=0;
void count_subset(int arr[],int n,int i,int sum,int k)
{
    if(sum==k)
    {
        c++;
        return;
    }
    if(i<n)
    {
        count_subset(arr,n,i+1,sum+arr[i],k);
        count_subset(arr,n,i+1,sum,k);
    }
}
int main()
{
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    count_subset(arr,n,0,0,k);
    cout<<c;
}
