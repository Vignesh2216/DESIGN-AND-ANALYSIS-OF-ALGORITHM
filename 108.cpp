#include<iostream>
using namespace std;
int fnd(int n){
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    return fnd(n-1)+fnd(n-2);
}
int main(){
    int n;
    cin>>n;
    int a=fnd(n);
    cout<<a;
}