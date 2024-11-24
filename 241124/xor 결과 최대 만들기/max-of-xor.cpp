#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int nums[20];
vector<int> ans;
int maxXor  = 0;

int makeXor() {
    int total = ans[0];
    for (int i = 1; i < ans.size(); i++) {
        total ^= ans[i];
    }
    return total;
}

void choose(int curNum, int cnt) {
    if (curNum == n + 1) {
        maxXor = max(maxXor, makeXor());
        return;
    }
    
    ans.push_back(nums[curNum]);
    choose(curNum + 1, cnt + 1);
    ans.pop_back();

    choose(curNum + 1, cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    choose(1, 0);
    cout << maxXor;
    return 0;
}