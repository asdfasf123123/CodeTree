#include <iostream>
using namespace std;

int N;
int dx[] = {0,-1,1,0};
int dy[] = {1,0,0,-1};
int dirChartoNum(char c) {
    if (c == 'E') {
        return 0;
    } else if (c == 'N') {
        return 1;
    } else if (c == 'S') {
        return 2;
    } else if (c == 'W') {
        return 3;
    }
}

int main() {
    cin >> N;
    int length = 0, x =0, y = 0; 
    while (N--) {
        char dirChar;
        int size;
        cin >> dirChar >> size;
        int dirNum = dirChartoNum(dirChar);

        for (int i = 0; i < size; i++) {
            x += dx[dirNum];
            y += dy[dirNum];
            length++;
            if (x == 0 && y == 0) {
                cout << length;
                exit(0); 
            }
        }
    }
    cout << -1;
    return 0;
}