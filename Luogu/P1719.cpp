#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>>a(n + 2, vector<ll>(n + 2)), pr(n + 2, vector<ll>(n + 2));
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            cin >> a[i][j];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] + a[i][j];
    ll ans = -0x3f3f3f3f;
    for(int x1 = 1;x1 <= n;x1 ++)
        for(int y1 = 1;y1 <= n;y1 ++)
            for(int x2 = x1;x2 <= n;x2 ++)
                for(int y2 = y1;y2 <= n;y2 ++){
                    ll cur = pr[x2][y2] - pr[x1 - 1][y2] - pr[x2][y1 - 1] + pr[x1 - 1][y1 - 1];
                    ans = max(cur, ans);
                }
    cout << ans << endl;
    return 0;
}