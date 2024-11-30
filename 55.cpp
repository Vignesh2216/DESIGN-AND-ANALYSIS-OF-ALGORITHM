// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) 
    {
        cin >> N;
        vector<long> arr;
        for (int i = 0; i < N; i++) 
        {
            int v;
            cin >> v;
            arr.push_back(v);
        }
        reverse(arr.begin(), arr.end());
        long max = 0;
        int j = 0;
        int len = N;
        while (j < N) {
            long f = arr[j];
            long l = arr[len-1];
            if(max < l + f) max = l + f;
            arr.push_back(f);
            j++;
            len++;
        }
        cout << max << "\n";
    }
    return 0;
}
