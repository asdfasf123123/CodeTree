#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> answer;

void Print() {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}
void choose(int cur_num) {
    if (cur_num == n + 1) {
        Print();
        return;
    }

    for (int i = 1; i <= k; i++) {
        answer.push_back(i);
        choose(cur_num + 1);
        answer.pop_back();
    }
}
int main() {
    cin >> k >> n;

    choose(1);
    return 0;
}