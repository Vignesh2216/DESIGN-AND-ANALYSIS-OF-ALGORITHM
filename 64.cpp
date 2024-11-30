// You are using GCC
#include <iostream>
using namespace std;
bool isMinHeap(int arr[], int n) 
{
    for (int i = 0; i <= (n / 2) - 1; i++) 
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] > arr[left]) 
        {
            return false;
        }
        if (right < n && arr[i] > arr[right]) 
        {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (isMinHeap(arr, n)) 
    {
        cout << "True" << endl;
    } 
    else 
    {
        cout << "False" << endl;
    }
    return 0;
}