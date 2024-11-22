#include <iostream>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n, t;

int arr[100][100];
int count[100][100];
// 각 칸에 오게되는 구슬의 수를 담는 next count.
// 기존 count를 그대로 활용하면 이전 구슬과 움직인 이후의 구슬을 구별 불가능.
// 따라서 이렇게 동시에 변화가 일어나야 한다면 새로운 배열을 만들어 주는것이 가장 좋다.
int nextCount[100][100];

void moveOne(int x, int y) {
    int maxVal = arr[x][y], nextX = x, nextY = y;
    for (int dirNum = 0; dirNum < 4; dirNum++) {
        int nx = x + dx[dirNum];
        int ny = y + dy[dirNum];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (maxVal < arr[nx][ny]) {
                maxVal = arr[nx][ny];
                nextX = nx; nextY = ny;
            }
        }
    }
    nextCount[nextX][nextY]++;
}

int main() {
    // 입력
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        count[r - 1][c - 1] = 1;
    }


    while (t--) {
        // nextCount 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nextCount[i][j] = 0;
            }
        }

        // 안에 있으면 움직이기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (count[i][j] == 1) {
                    moveOne(i, j);
                }
            }
        }

        // 복사하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nextCount[i][j] > 1) nextCount[i][j] = 0;
                count[i][j] = nextCount[i][j];
            }
        }    
    }

    int countAll = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count[i][j] == 1) {
                countAll++;
            }
        }
    }
    
    cout << countAll;

    return 0;
}