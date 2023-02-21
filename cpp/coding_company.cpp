
// https://cses.fi/problemset/task/1665

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = i - 1; k >= 0; k--) {
                if (t[i - 1] - t[k] <= j) {
                    dp[i][j] = (dp[i][j] + dp[k][j - (t[i - 1] - t[k])]) % MOD;
                }
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
