// You are using GCC
#include <bits/stdc++.h> 
using namespace std; 
void sorts(vector<int>& arr){
    unordered_map<int,int>freqMap;
    for(int num:arr){
        freqMap[num]++;
    }
    vector<pair<int,int>>freqVec;
    for(auto& it : freqMap){
        freqVec.push_back(it);
    }
    sort(freqVec.begin(),freqVec.end(), [&](const pair<int,int>& a,const pair<int,int>& b){
        if(a.second != b.second)
        return a.second > b.second;
        else
        return a.first < b.first;
    });
    for(auto& it : freqVec){
        for(int i=0;i<it.second;++i){
            cout<<it.first<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    sorts(a);
}