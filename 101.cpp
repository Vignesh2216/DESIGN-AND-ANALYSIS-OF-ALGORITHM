// You are using GCC
#include<iostream>
using namespace std;
int search(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i+1;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int z=search(a,n,x);
    if(z!=0){
        cout<<"The ticket number "<<x<<" is found at position "<<search(a,n,x)<<endl;
        cout<<"Congratulations!You have won the lottery";
    }
    else{
        cout<<"Sorry the ticket number "<<x<<" is not there.Better luck next time!";
    }
}