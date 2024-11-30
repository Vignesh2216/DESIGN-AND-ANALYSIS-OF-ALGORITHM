// You are using GCC
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class SegmentTree {
    int n;
    vector<int> tree;
    void build(const vector<int>& arr) {
        for (int i = 0; i < n; i++) tree[n + i] = arr[i];
        for (int i = n - 1; i > 0; i--) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    int rangeMin(int left, int right) {
        int result = INT_MAX;
        left += n;
        right += n;
        while (left <= right) {
            if (left % 2 == 1) result = min(result, tree[left++]);
            if (right % 2 == 0) result = min(result, tree[right--]);
            left /= 2;
            right /= 2;
        }
        return result;
    }
    public:
    SegmentTree(const vector<int>& arr) : n(arr.size()), tree(2 * n) {
        build(arr);
    }
    int getRangeMin(int left, int right) {
        return rangeMin(left, right);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int L, R;
    cin >> L >> R;
    SegmentTree segmentTree(arr);
    int minVal = segmentTree.getRangeMin(L, R);
    cout << "Minimum of values in range [" << L << "," << R << "] is = " << minVal << endl;
    return 0;
}