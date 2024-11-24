#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> ans;

void print() {
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}

void choose(int cur_num) {
    if (cur_num == n + 1) {
        print();
        return;
    }

    for (int i = 1; i <= k; i++) {
        if (cur_num < 3 || (i != ans[ans.size() - 1] && i != ans[ans.size() - 2])) {
            ans.push_back(i);
            choose(cur_num + 1);
            ans.pop_back();
        }
    }

      
}

int main() {
    cin >> k >> n;

    choose(1);

    return 0;
}