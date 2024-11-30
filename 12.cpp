// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
class SegmentTree {
    public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(2 * n);
        build(arr);
    }
    void update(int index, int value) {
        index += n;
        tree[index] = value;
        for (int i = index; i > 1; i /= 2) {
            tree[i / 2] = tree[i] + tree[i ^ 1];
        }
    }
    int rangeSum(int left, int right) {
        int result = 0;
        left += n;
        right += n;
        while (left <= right) {
            if (left % 2 == 1) result += tree[left++];
            if (right % 2 == 0) result += tree[right--];
            left /= 2;
            right /= 2;
        }
        return result;
    }
    private:
    int n;
    vector<int> tree;
    void build(vector<int>& arr) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int L, R, index, newValue;
    cin >> L >> R;
    cin >> index >> newValue;
    SegmentTree segmentTree(arr);
    int originalSum = segmentTree.rangeSum(L, R);
    cout << "Sum of values in given range = " << originalSum << endl;
    segmentTree.update(index, newValue);
    int updatedSum = segmentTree.rangeSum(L, R);
    cout << "Updated sum of values in given range = " << updatedSum << endl;
    
    return 0;
}