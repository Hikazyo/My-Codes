#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
vector<ll> a, apre, cnt;

void solve(int n, int k){
    ll ans = 0;
    for(int r = 1;r <= n;r ++){
        int i = r - k - 1;
        if(i >= 0) cnt[apre[i]] ++;

        ans += cnt[apre[r]];
    }
    cout << ans << endl;
    return ;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T --){
        int n, k;
        cin >> n >> k;
        a.assign(n + 2, 0);apre.assign(n + 2, 0);cnt.assign(n + 2, 0);
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            apre[i] = (apre[i - 1] + a[i]) % k;
        }
        solve(n, k);
    }
    return 0;
}