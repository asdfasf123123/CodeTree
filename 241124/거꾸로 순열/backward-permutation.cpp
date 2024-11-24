#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[9];
vector<int> ans;

void print() {
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
void choose(int curNum) {
    if (curNum == n + 1) {
        print();
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (visited[i])
            continue;

        visited[i] = true;
        ans.push_back(i);
        choose(curNum + 1);
        ans.pop_back();
        visited[i] = false;
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    choose(1);
    return 0;
}