// You are using GCC
#include <iostream>
using namespace std;
bool isMinHeap(int arr[], int n) 
{
    for (int i = 0; i <= (n / 2) - 1; i++) 
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (leftChild < n && arr[i] > arr[leftChild]) 
        {
            return false;
        }
        if (rightChild < n && arr[i] > arr[rightChild]) 
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
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    if (isMinHeap(arr, n)) 
    {
        cout << "Given array is a min heap" << endl;
    } 
    else 
    {
        cout << "Given array is not a min heap" << endl;
    }
    return 0;
}