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

    if (n == 1 && m == 1) {
        cout << 2;
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        int numrow = 1;
        int numcol = 1;
        for (int j = 1; j < n; j++) {
            if (arr[i][j] == arr[i][j - 1])
                numrow++;
            else numrow = 1;
            if (numrow == m) {
                cnt++;
                break;
            }
        }
        for (int j = 1; j < n; j++) {
            if (arr[j][i] == arr[j - 1][i])
                    numcol++;
                else numcol = 1;
                if (numcol == m) {
                    cnt++;
                    break;
                }
        }
    }
    cout << cnt;
    return 0;
}