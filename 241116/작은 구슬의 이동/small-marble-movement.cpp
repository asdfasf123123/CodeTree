#include <iostream>
using namespace std;

int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
int N;

int changeDirNum(char d) {
    int arr[128];
    arr['R'] = 0;
    arr['D'] = 1;
    arr['L'] = 3;
    arr['U'] = 2;
    return arr[d];
}

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    int t;
    int r, c;
    char d;
    cin >> N >> t;
    cin >> r >> c >> d;
    r--;    c--;
    int dirNum = changeDirNum(d);

    for (int i = 0; i < t; i++) {
        int nx = r + dx[dirNum], ny = c + dy[dirNum];

        if (!inRange(nx, ny)) { // not in range
            dirNum = 3 - dirNum;
            continue;
        }

        r += dx[dirNum], c += dy[dirNum];   
    }

    cout << ++r << " " << ++c;

    return 0;
}