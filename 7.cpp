// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
class SegmentTree {
    vector<int> tree;
    int n;
    int MOD;
    int buildTree(const vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            return tree[node] = arr[start] % MOD;
        }
        int mid = (start + end) / 2;
        int leftProduct = buildTree(arr, start, mid, 2 * node + 1);
        int rightProduct = buildTree(arr, mid + 1, end, 2 * node + 2);
        return tree[node] = (1LL * leftProduct * rightProduct) % MOD;
    }
    int rangeProduct(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return 1;
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        int leftProduct = rangeProduct(2 * node + 1, start, mid, L, R);
        int rightProduct = rangeProduct(2 * node + 2, mid + 1, end, L, R);
        return (1LL * leftProduct * rightProduct) % MOD;
    }
    public:
    SegmentTree(const vector<int>& arr, int P) : MOD(P) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }
    int rangeProduct(int L, int R) {
        return rangeProduct(0, 0, n - 1, L, R);
    }
};
int main() {
    int n, P;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> P;
    int L, R;
    cin >> L >> R;
    SegmentTree segmentTree(arr, P);
    if (L > R || L < 1 || R > n) {
        cout << "Invalid range" << endl;
    } else {
        int result = segmentTree.rangeProduct(L - 1, R - 1);
        cout << result << endl;
    }
    return 0;
}