// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int L, R;
    cin >> L >> R;
    if (L < 0 || R >= n || L > R) {
        cout << "Invalid range" << endl;
    } else {
        cout << "Elements in the range [" << L << ", " << R << "] are:";
        for (int i = L; i <= R; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
    return 0;
}