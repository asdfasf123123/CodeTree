#include <iostream>
using namespace std;
#define MAX_N 100

int arr[MAX_N][MAX_N];
int n;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void downArr(int n_) {
    for (int col = 0; col < n; col++) {
        int temp[n_] = {};
        int end_temp = n-1;
        for (int row = n-1; row >= 0; row--) {
            if (arr[row][col] != 0) {
                temp[end_temp] = arr[row][col];
                end_temp--;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i][col] = temp[i];
        }
    }
}

void bomb(int r, int c) {
    r--; c--;
    int size = arr[r][c];
    int dirNum = 3;
    while (dirNum >= 0) {
        for (int i = 0; i < size; i++) {
            int nx = r + dx[dirNum] * i;
            int ny = c + dy[dirNum] * i;
            if (nx < n && ny < n && nx >= 0 && ny >= 0) {
                arr[nx][ny] = 0;
            }
        }
        dirNum--;
    }
    downArr(n);
}

void printArray() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int r, c;
    cin >> r >> c;

    bomb(r, c);
    printArray();
    return 0;
}