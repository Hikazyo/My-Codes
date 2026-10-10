#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct mine{
    ll w, v;
};
ll n, m, s, w = 0;//下次数据记得开大一点  要么就直接using long long int
ll ans = 1e18, y = 0;
vector<mine>a; 
vector<ll>l, r;


ll check(ll W){
    ll y = 0;
    vector<ll>p1(n + 1, 0), p2(n + 1, 0);
    for(int i = 1;i <= n;i ++){
        if(a[i].w >= W){
            p1[i] = p1[i - 1] + 1;
            p2[i] = p2[i - 1] + a[i].v;
        }
        else{
            p1[i] = p1[i-1];            
            p2[i] = p2[i-1];
        }
    }
    for(int i = 1; i <= m; i ++)
        y += (p1[r[i]] - p1[l[i] - 1]) * (p2[r[i]] - p2[l[i] - 1]);

    return y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    a.resize(n+1); l.resize(m+1); r.resize(m+1);
    ll wmax = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].w >> a[i].v;
        wmax = max(wmax, a[i].w);
    }
    for(int i = 1;i <= m;i ++)cin >> l[i] >> r[i];
    
    ll L = 1, R = wmax + 1;
    while(L <= R){
        ll mid = (L + R) >> 1;
        ll y = check(mid);
        ans = min(ans , llabs(y - s));
        if(y == s)break;
        if(y > s)L = mid + 1;
        else R = mid - 1;
    } 
    
    cout << ans << endl;
    return 0;
}