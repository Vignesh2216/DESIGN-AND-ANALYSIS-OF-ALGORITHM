// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int a[6];
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    int z;
    cin>>z;
    int q=0;
    for(int i=0;i<6;i++){
        if(a[i]==z){
            cout<<i;
            q=1;
            break;
        }
    }
    if(q==0)
    cout<<-1;
}