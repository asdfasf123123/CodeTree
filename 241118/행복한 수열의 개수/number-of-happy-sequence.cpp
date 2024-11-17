#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int numrow = 1;
        int numcol = 1;
        for (int j = 1; j < n; j++) {
            if (arr[i][j] == arr[i][j - 1])
                numrow++;
            else numrow = 1;

            if (arr[j][i] == arr[j - 1][i])
                numcol++;
            else numcol = 1;
        }
        if (numrow >= m) cnt++;
        if (numcol >= m) cnt++;
    }
    cout << cnt;
    return 0;
}