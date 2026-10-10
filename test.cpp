#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;
const int MAXN = 1000000;

long long inv[MAXN + 1];
long long ans[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    ans[2] = 2;
    for (int n = 3; n <= MAXN; n++) {
        ans[n] = ans[n - 1] * 4 % MOD * (2LL * n - 5) % MOD * inv[n - 1] % MOD;
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}