#include <iostream>
using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0 ,1};

int n, m, canGoNum = 0;
int arr[101][101];
int visited[101][101];

bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canGo(int x, int y) {
    if (!inRange(x, y)) {
        return false;
    }
    if (visited[x][y] || arr[x][y] == 0) {
        return false;
    }
    return true;
}
void dfs(int x, int y) {
    for (int i = 0; i < 2; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (canGo(new_x, new_y)) {
            if (new_x == n-1 && new_y == m-1) {
                canGoNum = 1;
                return;
            }
            visited[new_x][new_y] = true;
            dfs(new_x, new_y);
        }
    }
}

int main() {
    cin >> n>> m;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0,0);

    cout << canGoNum;
    return 0;
}