// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string x;
    cin>>x;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            cout<<"Name found at index "<<i;
            return 0;
        }
    }
    cout<<"Name not found in the list.";
    return 0;
}