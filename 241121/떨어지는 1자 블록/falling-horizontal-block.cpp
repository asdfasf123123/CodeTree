#include <iostream>
using namespace std;

int n,m;
int arr[100][100];

void stop_block(int now, int col) {
    if (now == -1) return;
    for (int i = col; i < (col + m); i++) {
        arr[now][i] = 1;
    }
}

void block_down(int r) {
    for (int now = -1; now < n; now++) {
        int next = now + 1;
        for (int col = r; col < (r + m); col++) {
            if (arr[next][col] != 0) {
                stop_block(now, r);
                return;
            }
        }
        if (now == n - 1) {
            stop_block(now,r);
        }
    }
}

void print_arr() {
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++)
            cin >> arr[i][j];
    } 

    block_down(r - 1);

    print_arr();
    return 0;
}