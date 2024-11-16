#include <iostream>
#include <string>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    string str;
    cin >> str;
    int x=0, y=0;
    int dirNum = 0;

    for(char i:str) {
        if (i == 'L') {
            dirNum += 3;
        }
        else if (i == 'R') {
            dirNum += 1;
        }
        else if (i == 'F') {
            x += dx[dirNum % 4];
            y += dy[dirNum % 4];
        }
    }
    cout << x << " " << y;
    return 0;
}