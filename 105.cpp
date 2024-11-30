// You are using GCC
#include<iostream>
using namespace std;
int no(int n){
    if(n==0)
    return 0;
    return 1+no(n/10);
}
int main(){
    int n;
    cin>>n;
    cout<<"The number of digits in "<<n<<" is "<<no(n);
}