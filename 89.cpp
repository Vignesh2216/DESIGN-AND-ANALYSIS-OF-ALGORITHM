// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct DOB{
    int date;
    int month;
    int year;
};
bool comp(DOB& a,DOB& b){
    if(a.year==b.year){
        if(a.month == b.month){
            return a.date<b.date;
        }
    }
    else{
        return a.year<b.year;
    }
}
int main(){
    int n;
    cin>>n;
    vector<DOB> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].date;
        cin>>v[i].month;
        cin>>v[i].year;
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        cout<<v[i].date<<" "<<v[i].month<<" "<<v[i].year;
        cout<<endl;
    }
}