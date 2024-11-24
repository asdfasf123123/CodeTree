#include <vector>
#include <iostream>
using namespace std;

int n, m, k;
int mal[4];
int dis[12];
int maxNum = 0, sum = 0;

void play(int cur_num) {
    sum = 0;
    for (int i = 0; i< k; i++) {
        if (mal[i] >= m)
            sum++;
    }
    if (maxNum < sum) {
        maxNum = sum;
    }

    if (cur_num == n) {
        return;
    }

    for (int i = 0; i < k; i++) {
        if (mal[i] >= m) 
            continue;
        mal[i] += dis[cur_num];
        play(cur_num + 1);
        mal[i] += dis[cur_num];

    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> dis[i];
    }
    for (int i = 0; i < k; i++) {
        mal[i] = 1;
    }

    play(0);

    cout << maxNum;
    return 0;
}