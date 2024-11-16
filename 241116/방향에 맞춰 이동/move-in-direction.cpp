#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N;
    cin >> N;
    int x = 0, y = 0;

    // 방향 벡터!
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    // if (dirNum == 0) {
    //     nx = x + d[0], ny = y + d[0];
    // }
    // else if (dirNum == 1) {
    //     nx = x + d[1], ny = y + d[1];
    // }
    // else if (dirNum == 2) {
    //     nx = x + d[2], ny = y + d[2];
    // }
    // else if (dirNum == 3) {
    //     nx = x + d[3], ny = y + d[3];
    // }
    for (int i = 0; i < N; i++) {
        // 이동에 대한 코드는 고정
        char dirChar;
        int size, dirNum;
        cin >> dirChar >> size;
        if (dirChar == 'N') {
            dirNum = 3;
        } else if (dirChar == 'E') {
            dirNum = 0;
        } else if (dirChar == 'S') {
            dirNum = 1;
        } else if (dirChar == 'W') {
            dirNum = 2;
        }

        x = x + dx[dirNum] * size;
        y = y + dy[dirNum] * size;
    }

    cout << x << " " << y;

    return 0;
}