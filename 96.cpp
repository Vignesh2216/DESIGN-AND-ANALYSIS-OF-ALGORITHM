// You are using GCC
#include<iostream>
using namespace std;
int ck(int n,string s[],string x){
    for(int i=0;i<n;i++){
        if(s[i]==x)
        return i;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    string x;
    cin>>x;
    if(ck(n,s,x)!=-1){
        cout<<"Name found at index "<<ck(n,s,x);
    }
    else{
        cout<<"Name not found in the list.";
    }
}