// You are using GCC
#include<iostream>
using namespace std;
struct Act
{
    string e;
    int b,c;
};
int main()
{
    int n;
    cin>>n;
    Act a[n];
    for(int i=0;i<n;i++)
        cin>>a[i].e>>a[i].b>>a[i].c;
        
    for(int i=0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(a[j].c>=a[j+1].c){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<"Selected Activities are:"<<endl;
    cout<<a[0].e<<" ";
    int j=0;
    for(int i=1;i<=n;i++){
        if(a[j].c<=a[i].b){
            cout<<a[i].e<<" ";
            j=i;
        }
    }
}