#include <bits/stdc++.h>

using namespace std;
const int N = 1001;
const int MOD = 1e9+7;
int n;
long long dp[N], p[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    // dp[i] = -dp[p[i]] +2*dp[i-1] + 2
    dp[1] = 2;
    for (int i = 1;i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 2; i <= n; ++i) {
        if (p[i] == i) dp[i] = 2;
        else {
            dp[i] = 2;
            for (int j = p[i]; j < i; ++j) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    cout << dp[n] << '\n';
    return 0;
}
