#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    n *= 3;
    t %= n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < t; i++) {
        int temp = arr[n - 1];
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << "\n";
    }
    
    return 0;
}