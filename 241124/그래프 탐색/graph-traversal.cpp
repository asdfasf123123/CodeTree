#include <iostream>
using namespace std;

int n, m;
int graph[1001][1001];
int vertex_cnt;
bool visited[1001];

void dfs(int vertex) {
    for (int cur_v = 1; cur_v <= n; cur_v++) {
        if (graph[vertex][cur_v] && !visited[cur_v]) {
            visited[cur_v] = true;
            vertex_cnt++;
            dfs(cur_v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    visited[1] = true;
    dfs(1);

    cout << vertex_cnt;
    return 0;
}