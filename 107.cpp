// You are using GCC
#include<iostream>
using namespace std;
int re(int n1,int n2){
    if(n1==0)
    return n2;
    if(n2==0)
    return n1;
    if(n1>n2)
    re(n1%n2,n2);
    else
    re(n1,n2%n1);
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    cout<<"G.C.D of "<<n1<<" and "<<n2<<" is "<<re(n1,n2);
}