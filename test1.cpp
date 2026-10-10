#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    const long long NEG = LLONG_MIN / 4;   // 防止加法溢出

    long long dp0 = NEG;  // 未开始调制（前缀）
    long long dp1 = NEG;  // 调制进行中（乘 x 的中间段）
    long long dp2 = NEG;  // 调制已结束（后缀）
    long long ans = NEG;

    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        long long xv = v * x;

        long long ndp0 = max(dp0 + v, v);            // 延续前缀 / 重新起段
        long long ndp1 = max({dp1 + xv, dp0 + xv, xv}); // 延续调制 / 前缀后开调 / 直接调制开头
        long long ndp2 = max({dp2 + v, dp1 + v, v}); // 延续后缀 / 调制刚结束 / 全新原值段

        dp0 = ndp0;
        dp1 = ndp1;
        dp2 = ndp2;

        ans = max(ans, max(dp0, max(dp1, dp2)));
    }

    cout << ans << '\n';
    return 0;
}
