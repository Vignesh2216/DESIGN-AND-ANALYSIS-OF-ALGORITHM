// You are using GCC
#include<iostream>
#include<algorithm>
#include<queue>
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
    priority_queue<int,vector<int>,greater<>>q;
    for(int i=0;i<n;i++){
        q.push(a[i]);
    }
    cout<<endl<<"Sorted Array (Heap Sort): ";
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}