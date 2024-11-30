// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int a[5];
    for(int i=0;i<5;i++)
    cin>>a[i];
    int x;
    cin>>x;
    int z=0;
    for(int i=0;i<5;i++){
        if(a[i]==x){
        cout<<"Yes";
        z=1;
        break;
        }
    }
    if(z==0)
    cout<<"No";
    
}