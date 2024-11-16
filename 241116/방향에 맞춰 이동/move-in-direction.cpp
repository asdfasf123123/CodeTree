#include <iostream>
using namespace std;

// 방향 벡터!
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    int mapper[200];
    mapper['E'] = 0;
    mapper['S'] = 1;
    mapper['W'] = 2;
    mapper['N'] = 3;

    int N;
    cin >> N;
    int x = 0, y = 0;

    for (int i = 0; i < N; i ++) {
        char dirChar;
        int size;
        cin >> dirChar >> size;
        int dirNum = mapper[dirChar];
        x = x + dx[dirNum] * size;
        y = y + dy[dirNum] * size;
    }

    cout << x << " " << y;
    return 0;
}

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


// for (int i = 0; i < N; i++) {
//         // 이동에 대한 코드는 고정
//         char dirChar;
//         int size, dirNum;
//         cin >> dirChar >> size;
//         if (dirChar == 'N') {
//             dirNum = 3;
//         } else if (dirChar == 'E') {
//             dirNum = 0;
//         } else if (dirChar == 'S') {
//             dirNum = 1;
//         } else if (dirChar == 'W') {
//             dirNum = 2;
//         }
