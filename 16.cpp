// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int maxApplications(vector<int>& server_capacity,vector<int>& app_requirements)
{
    int total_capacity=0;
    for(int capacity:server_capacity)
    {
        total_capacity+=capacity;
    }
    sort(app_requirements.begin(),app_requirements.end());
    int app_count=0;
    for(int requirement:app_requirements)
    {
        if(total_capacity>=requirement)
        {
            total_capacity-=requirement;
            app_count++;
        }
        else
        {
            break;
        }
    }
    return app_count;
}
int main()
{
    int N,M;
    cin>>N;
    vector<int>server_capacity(N);
    for(int i=0;i<N;i++)
    {
        cin>>server_capacity[i];
    }
    cin>>M;
    vector<int>app_requirements(M);
    for(int i=0;i<M;i++)
    {
        cin>>app_requirements[i];
    }
    int result=maxApplications(server_capacity,app_requirements);
    cout<<result<<endl;
    return 0;
}