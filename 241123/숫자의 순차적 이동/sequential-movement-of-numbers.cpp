#include <iostream>
using namespace std;

int n, m;
int arr[21][21];
int index[401][2];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inRange(int nx, int ny) {
    return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

void swapIndex(int i1, int i2) {
    int temp[2];
    for (int i = 0; i < 2; i++) {
        temp[i] = index[i1][i];
    }
    for (int i = 0; i < 2; i++) {
        index[i1][i] = index[i2][i];
        index[i2][i] = temp[i];
    }
    
}

void swapArr(int x, int y, int nx, int ny) {
    int temp = arr[x][y];
    arr[x][y] = arr[nx][ny];
    arr[nx][ny] = temp;
}

void moveArr() {
    for (int i = 1; i <= n * n; i++) {
        int x = index[i][0], y = index[i][1];
        int max = 0;
        int newx, newy;
        for (int dirNum = 0; dirNum < 8; dirNum++) {
            int nx = x + dx[dirNum], ny = y + dy[dirNum];
            if (inRange(nx, ny) && arr[nx][ny] > max) {
                max = arr[nx][ny];
                newx = nx;  newy = ny;
            }
        }
        swapArr(x, y, newx, newy);
        swapIndex(i, max);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            index[arr[i][j]][0] = i, index[arr[i][j]][1] = j;
        }
    }

    while (m--) {
        moveArr();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}