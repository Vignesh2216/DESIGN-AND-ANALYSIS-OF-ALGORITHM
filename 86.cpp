// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct st{
    int r;
    string n;
    int m;
    int p;
    int c;
    int sum;
    double avg;
};
bool comp(st& a,st& b){
    if(a.sum>b.sum)
    return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<st> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i].r;
        cin>>x[i].n;
        cin>>x[i].m;
        cin>>x[i].p;
        cin>>x[i].c;
    }
    for(int i=0;i<n;i++){
        x[i].sum=x[i].m+x[i].c+x[i].p;
        x[i].avg=x[i].sum/3.0;
    }
    sort(x.begin(),x.end(),comp);
    for(int i=0;i<n;i++){
        cout<<x[i].r<<" ";
        cout<<x[i].n<<" ";
        cout<<x[i].sum<<" ";
        cout<<fixed<<setprecision(2)<<x[i].avg<<endl;
    }
}