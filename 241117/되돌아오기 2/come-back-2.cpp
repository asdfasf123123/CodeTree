#include <iostream>
#include <string>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main() {
    string in;
    cin >> in;
    int x = 0, y = 0, length = 0;
    int dirNum = 0;
    for (char i : in) {
        if (i == 'F') {
            x += dx[dirNum];
            y += dy[dirNum];
        } else if (i == 'R') {
            dirNum = (dirNum + 1) % 4;
        } else if (i == 'L') {
            dirNum = (dirNum + 3) % 4;
        }
        length++;
        if (x == 0 && y == 0) {
            cout << length;
            exit(0);
        }
    }
    cout << -1;
    return 0;
}