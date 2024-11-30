// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, vector<int>& weights, vector<int>& values, int n)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]],K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int n;
    cin>>n;
    vector<int>values(n);
    for(int i=0;i<n;i++)
        cin>>values[i];
        
    vector<int>weights(n);
    for(int i=0;i<n;i++)
        cin>>weights[i];
    
    int W;
    cin>>W;
    cout << knapSack(W, weights,values, n);
}