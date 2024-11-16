#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1,0};
int n, m;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    int dirNum = 0;
    cin >> n >> m;
    int ans[n][m] = {};
    int x = 0, y = 0;

    for(int i = 0; i < n * m; i++) {
        ans[x][y] = i + 1;
        int nx = x + dx[dirNum];
        int ny = y + dy[dirNum];
        if (!InRange(nx, ny) || ans[nx][ny] != 0)
            dirNum = (dirNum+1) % 4;
        x += dx[dirNum];
        y += dy[dirNum];
    }   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}