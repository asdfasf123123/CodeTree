#include <iostream>
using namespace std;
int N;
int Max = 3;


int main() {
    cin >> N;
    int arr[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    int x = 0, y = 0, maxGold = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (row + 2 >= N || col + 2 >= N)
                break;
            
        int numOfGold = 0;
        for (int r = row; r < row + 3; r++) {
            for (int c = col; c < col + 3; c++) {
                if (arr[r][c] == 1) {
                    numOfGold++;
                }
            }
        }
        maxGold = max(maxGold, numOfGold);
        }
    }
    cout << maxGold;
    return 0;
}