#include <bits/stdc++.h>
using namespace std;
const int MAX = 500;
int st[MAX][MAX];
void buildSparseTable(int arr[], int n) {
    for (int i = 0; i < n; i++)
    st[i][0] = arr[i];
    for (int j = 1; j <= log2(n); j++) {
        for (int i = 0; (i + (1<<j- 1)) < n; i++) {
            st[i][j]=min(st[i][j - 1] , st[i + (1<<j-1)][j - 1]);
        }
    }
}
int query(int L, int R) {
    int k = log2(R - L + 1);
    return min(st[L][k], st[R-(1<<k)+1][k]);
}
int main() {
    int n, s1, e1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    buildSparseTable(arr, n);
    cin >> s1 >> e1;
    cout << query(s1, e1) << endl;
    return 0;
}