#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;
vector<int> answer;

bool is_beautiful_num() {
    for(int i = 0; i < answer.size(); i++) {
        int current = answer[i];
        for (int j = 0; j < current - 1; j++) {
            i++;
            if (answer[i] != current) {
                return false;
            }
        }
    }
    return true;
}

void choose(int cur_num) {
    if (cur_num == n+1) {
        if (is_beautiful_num()) {
            cnt++;
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        answer.push_back(i);
        choose(cur_num+1);
        answer.pop_back();
    }
}

int main() {
    cin >> n;

    choose(1);
    cout << cnt;
    return 0;
}