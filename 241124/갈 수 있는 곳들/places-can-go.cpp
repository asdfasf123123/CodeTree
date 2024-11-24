#include <iostream>
#include <queue>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

// 전역 변수 선언:
int n, k;
int grid[MAX_N][MAX_N];

// bfs에 필요한 변수들 입니다.
queue<pair<int, int> > bfs_q;
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && !grid[x][y] && !visited[x][y];
}

void BFS() {
    // queue에 남은 것이 없을때까지 반복합니다.
    while(!bfs_q.empty()) {
        // queue에서 가장 먼저 들어온 원소를 뺍니다.
        pair<int, int> curr_pos = bfs_q.front();
        int x = curr_pos.first, y = curr_pos.second;
        bfs_q.pop();

        int dx[DIR_NUM] = {1, -1, 0, 0};
        int dy[DIR_NUM] = {0, 0, 1, -1};

        // queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            // 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            // 새로 queue에 넣어주고 방문 여부를 표시해줍니다. 
            if(CanGo(nx, ny)){
                bfs_q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

}

int main() {
    // 입력:
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    // 시작점을 모두 bfs queue에 넣습니다.
    while(k--) {
        int x, y;
        cin >> x >> y;
        bfs_q.push(make_pair(x - 1, y - 1));
        visited[x - 1][y - 1] = true;
    }
    
    // bfs를 진행합니다.
    BFS();

    int ans = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(visited[i][j])
                ans++;
    
    cout << ans;

    return 0;
}