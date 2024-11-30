// You are using GCC
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class SegmentTree {
    int n;
    vector<unordered_map<int, int>> tree;
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node][arr[start]]++;
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            for (auto& p : tree[2 * node + 1]) tree[node][p.first] += p.second;
            for (auto& p : tree[2 * node + 2]) tree[node][p.first] += p.second;
        }
    }
    int query(int node, int start, int end, int L, int R, int X) {
        if (R < start || L > end) return 0;
        if (L <= start && end <= R) {
            return tree[node].count(X) ? tree[node][X] : 0;
        }
        int mid = (start + end) / 2;
        int leftQuery = query(2 * node + 1, start, mid, L, R, X);
        int rightQuery = query(2 * node + 2, mid + 1, end, L, R, X);
        return leftQuery + rightQuery;
    }
    public:
    SegmentTree(const vector<int>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    int getFrequency(int L, int R, int X) {
        return query(0, 0, n - 1, L, R, X);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int L, R, X;
    cin >> L >> R >> X;
    SegmentTree segmentTree(arr);
    int frequency = segmentTree.getFrequency(L, R, X);
    cout << "Frequency of " << X << " in the range [" << L << ", " << R << "] is: " << frequency << endl;
    return 0;
}