#include <iostream>
using namespace std;

int n;
int arr[100][100];

void block_down(int m, int r) {
    for (int row = 0; row < n; row++) {
        for (int i = r; i < r + m; i++) {
            if (arr[row][i] != 0) {
                stop_block(row, r);
                return;
            }
        }
    }
}

void stop_block(int row, int r) {
    for (int i = r; i < r + m; i++) {
        arr[row][r] = 1;
    }
}

void print_arr() {
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++)
            cout << arr[i][j];
    }
}

int main() {
    int m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++)
            cin >> arr[i][j];
    } 

    block_down(m, r - 1);

    print_arr();
    return 0;
}