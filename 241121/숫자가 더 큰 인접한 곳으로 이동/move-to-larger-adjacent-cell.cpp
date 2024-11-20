#include <iostream>
#include <cmath>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
int arr[100][100];

bool inRange(int x, int y) {
    return x >= 0 && x < n && y >=0 && y < n;
}

void move_and_print(int r, int c) {
    cout << arr[r][c] << " ";
    while (true) {
        int maxVal = arr[r][c];
        for (int dirNum = 0; dirNum < 4; dirNum++) {
            int nx = r + dx[dirNum];
            int ny = c + dy[dirNum];
            if (inRange(nx, ny)) {
                if (maxVal < arr[nx][ny]) {
                    cout << arr[nx][ny] << " ";
                    r = nx; c = ny;
                    continue;
                }
            }
        }
        if (maxVal == arr[r][c]) break;
    }
}

int main() {
    int r, c;
    cin >> n >> r >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    move_and_print(r-1, c-1);
    return 0;
}