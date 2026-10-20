#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;
ll n, x, ans = 0;

int main(){
    cin >> n >> x;
    vector<ll> a(n + 1);
    for(int i = 1;i <= n;i ++){
        int k;
        cin >> k;
        a[i] = k;
    }
    vector<ll> pr(n + 2, 0), l(n + 2), r(n + 2);

    pr[0] = l[0] = r[n + 1] = 0;
    for(int i = 1;i <= n;i ++)pr[i] += pr[i - 1] + a[i];
    for(int i = 1;i <= n;i ++)l[i] = max(ll(0), l[i - 1] + a[i]);
    for(int i = n;i >= 1;i --)r[i] = max(ll(0), r[i + 1] + a[i]);
    
    ll cur = 0, maxs = -INF;
    for(int i = 1;i <= n;i ++){
        cur = max(a[i], cur + a[i]);
        maxs = max(maxs, cur);
    }    

    ll maxl = -INF, turn = -INF;
    for(int i = 1;i <= n;i ++){
        ll lv = l[i - 1] - x * pr[i - 1];
        maxl = max(lv, maxl);
        ll rv = x * pr[i] + r[i + 1];
        turn = max(turn, maxl + rv);
    } 
    
    ans = max(maxs, turn);
    cout << ans << endl;
    return 0;
}