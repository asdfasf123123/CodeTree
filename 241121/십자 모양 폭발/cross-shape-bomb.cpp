#include <iostream>
#include <cmath>

using namespace std;
#define MAX_N 200

int arr[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];
int n;

bool inRange(int x, int y, int centerX, int centerY, int size) {
    return (x == centerX || y == centerY) && abs(x - centerX) + abs(y - centerY) < size;
}

void bomb(int r, int c) {
    int size = arr[r][c];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (inRange(i, j, r, c, size))
                arr[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        int next_row = n - 1;
		for(int i = n - 1; i >= 0; i--) {
			if(arr[i][j])
				temp[next_row--][j] = arr[i][j];
		}
    }
	
    // Step3. grid로 다시 값을 옮겨줍니다.
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            arr[i][j] = temp[i][j];

}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int r, c;
    cin >> r >> c;

    bomb(r- 1, c - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}