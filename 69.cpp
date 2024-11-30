// You are using GCC
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Original Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Min Heap: ";
    make_heap(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}