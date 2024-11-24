#include <iostream>

#define MAX_N 1000
#define MOD 10007

using namespace std;

// 변수 선언
int n;

int dp[MAX_N + 1];

int main() {
    // 입력:
    cin >> n;

    // 초기 조건 설정
    dp[0] = 1;
    dp[1] = 1;

    // 점화식에 따라 dp값 채우기
    // dp[i] = dp[i - 1] + dp[i - 2]
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    cout << dp[n];
    return 0;
}