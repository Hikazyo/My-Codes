#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct C{
    ll w, l, r;
    bool operator<(const C& o) const { return w > o.w; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll m;
    cin >> n >> m;
    vector<C> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].w >> a[i].l >> a[i].r;
    sort(a.begin(), a.end());
    vector<ll> pl(n+1), pr(n+1), prs(n+1), pls(n+1);
    for (int i = 0; i < n; ++i) {
        pl[i+1] = pl[i] + a[i].l;
        pr[i+1] = pr[i] + a[i].r;
        prs[i+1] = prs[i] + a[i].w * a[i].r;
        pls[i+1] = pls[i] + a[i].w * a[i].l;
    }
    vector<ll> sl(n+1), sr(n+1), sls(n+1), srs(n+1);
    for (int i = n-1; i >= 0; --i) {
        sl[i] = sl[i+1] + a[i].l;
        sr[i] = sr[i+1] + a[i].r;
        sls[i] = sls[i+1] + a[i].w * a[i].l;
        srs[i] = srs[i+1] + a[i].w * a[i].r;
    }
    vector<int> L(n), R(n);
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[j].w == a[i].w) j++;
        j--;
        for (int k = i; k <= j; ++k) L[k] = i, R[k] = j;
        i = j + 1;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll sS = pr[i] + (pl[R[i]] - pl[L[i]] - a[i].l) + sl[i+1];
        ll smin = pl[i] + (pl[R[i]] - pl[L[i]] - a[i].l) + sl[i+1];
        ll smax = pr[i] + (pr[R[i]] - pr[L[i]] - a[i].r) + sr[i+1];
        ll low = max(smin, 0LL), high = min(smax, m);
        ll s = max(low, min(sS, high));
        ll xi = m - s;
        ll res = prs[i] + (pls[R[i]] - pls[L[i]] - a[i].l*a[i].w) + sls[i+1] + xi*a[i].w;
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
