#include <iostream>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N;

bool inRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    cin >> N;
    int arr[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int nx, ny, cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int oneCount = 0;
            for (int dirNum = 0; dirNum < 4; dirNum++) {
                nx = i + dx[dirNum];
                ny = j + dy[dirNum];
                if (inRange(nx, ny) && arr[nx][ny] == 1) {
                    oneCount++;
                }
            }
            if (oneCount >= 3) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}