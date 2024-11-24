#include <iostream>
#include <vector>
using namespace std;
int m, n;
vector<int> ans;

void print() {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void choose(int cur_num, int cnt) {
    if (cur_num == n + 1) {
        if (cnt == m) {
            print();
        }
        return;
    }

    ans.push_back(cur_num);
    choose(cur_num + 1, cnt + 1);
    ans.pop_back();

    choose(cur_num + 1, cnt);
    
}

int main() {
    cin >> n >> m;

    choose(1, 0);
    return 0;
}