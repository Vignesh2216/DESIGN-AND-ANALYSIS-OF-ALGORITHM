// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
class SegmentTree {
    vector<int> tree;
    int n;
    public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, L, R);
        int rightSum = query(2 * node + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }
    int totalSum(int node, int start, int end) {
        if (start == end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return totalSum(2 * node + 1, start, mid) + totalSum(2 * node + 2, mid + 1, end);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int L, R;
    cin >> L >> R;
    if (L > R || L < 0 || R >= n) {
        cout << "Invalid range" << endl;
        return 0;
    }
    SegmentTree segmentTree(arr);
    int totalSum = segmentTree.totalSum(0, 0, n - 1);
    int rangeSum = segmentTree.query(0, 0, n - 1, L, R);
    int outsideRangeSum = totalSum - rangeSum;
    cout << "The sum of the elements not in the range [" << L << ", " << R << "] is: " << outsideRangeSum << endl;
    return 0;
}