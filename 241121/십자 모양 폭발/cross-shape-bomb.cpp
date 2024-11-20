#include <iostream>
using namespace std;
#define MAX_N 100

int arr[MAX_N][MAX_N];
int n;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void downArr() {
    for (int col = 0; col < n; col++) {
        int end_temp = n-1;
        for (int row = n-1; row >= 0; row--) {
            if (arr[row][col] != 0) {
                arr[end_temp][col] = arr[row][col];
                if (end_temp != row) {
                    arr[row][col]=0;
                }
                end_temp--;
            }
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
    downArr();
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