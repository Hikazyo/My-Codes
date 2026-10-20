#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int n, q;
vector<ll> l, r, pl, pr;//前后缀处理l, r

void solve(int s, int t){
    ll ans = 0;
    if(s < t){
        ans = r[s];                                          
        if(s >= 2)
            ans = min(ans, l[s] + pr[s - 1]);       
    } 
    else{
        ans = l[s];                                            
        if(s <= n - 1)
            ans = min(ans, r[s] + pl[s + 1]);     
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    l.resize(n + 3, INF);r.resize(n + 3, INF);pl.resize(n + 3, INF);pr.resize(n + 3, INF);
    for(int i = 2;i <= n;i ++)cin >> l[i];
    for(int i = 1;i <= n - 1;i ++)cin >> r[i];

    for(int i = 1;i <= n - 1;i ++)pr[i] = min(pr[i - 1], r[i]);
    for(int i = n;i >= 2;i --)pl[i] = min(pl[i + 1], l[i]);

    while(q --){
        int s, t;
        cin >> s >> t;
        solve(s, t);
    }
    return 0;
}
