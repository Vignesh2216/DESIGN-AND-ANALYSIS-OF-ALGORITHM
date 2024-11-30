// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
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
    int maxValue = arr[L];
    for (int i = L; i <= R; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    cout << "The maximum value in the range [" << L << ", " << R << "] is: " << maxValue << endl;
    return 0;
}