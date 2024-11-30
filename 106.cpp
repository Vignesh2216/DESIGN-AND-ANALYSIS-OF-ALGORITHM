// You are using GCC
#include<iostream>
using namespace std;
void re(int n){
    if(n<10){
        cout<<n;
    }
    else{
        cout<<n%10;
        re(n/10);
    }
}
int main(){
    int n;
    cin>>n;
    re(n);
}