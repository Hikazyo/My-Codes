#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, q;
vector<ll> a, b, c, d, cnt, id;

void solve(int x, int p, int v){
    if(x == 1)c[p] = v;
    else d[p] = v;
    sort(c.begin() + 1, c.end());
    sort(d.begin() + 1, d.end());
    for(int i = 1;i <= k;i ++){
        if(c[i] == d[i]) cnt[id[i]] ++;
        if(cnt[id[i]] % 2 == 0)cout << '0' << ' ';
        else cout << '1' << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k >> q;
    a.resize(k + 1);b.resize(k + 1);
    c.resize(k + 1);d.resize(k + 1);
    cnt.resize(k + 1);id.resize(k + 1);
    for(int i = 1; i <= k;i ++){
        cin >> a[i] >> b[i];
        c[i] = a[i];
        d[i] = b[i];
    }
    sort(c.begin() + 1, c.end());
    sort(d.begin() + 1, d.end());
    iota(id.begin() + 1,id.end(), 1);
    while(q --){
        int x, p, v;
        cin >> x >> p >> v;
        solve(x, p, v);
    }

    return 0;
}