// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double w[n],p[n],r[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
        r[i]=(p[i]/w[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(r[j]<=r[j+1]){
                swap(r[j],r[j+1]);
                swap(w[j],w[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }
    double sum;
    cin>>sum;
    double psum =0.0;
    for(int i=0;i<n;i++){
        if(w[i]<=sum){
            sum-=w[i];
            psum+=p[i];
        }else{
            psum += p[i]*(sum/w[i]);
            break;
        }
    }
    cout<<"Maximum profit is:- "<<fixed<<setprecision(2)<<psum;
}