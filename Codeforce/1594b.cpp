#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int T;
int n;
string a, b;
ll ans = 0;

void solve(){
    cin >> n >> b >> a;
    b = "0" + b;
    a = "0" + a;
    vector<vector<ll>> dp(n + 2, vector<ll>(2, -INF));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i ++){
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        if(a[i] == '1'){
            if(b[i] == '0'){
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            }
            if(b[i - 1] == '1' && i > 1){
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            }
            if(i < n && b[i + 1] == '1'){
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + 1);
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
            }
        }
    }

    cout << max(dp[n][1], dp[n][0]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}