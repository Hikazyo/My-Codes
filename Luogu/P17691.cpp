#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, T;
vector<ll>a, b, prea, preb;
ll ans = -1;


void solve(){
    ll cur = 0;
    int i = 1, j = 1;
    int l1 = 0, l2 = 0;
    ll suma = 0, sumb = 0;
    while(i <= n && j <= m){
        suma = prea[i] - prea[l1];
        sumb = preb[j] - preb[l2];
        if(suma == sumb){
            cur ++;
            l1 = i, l2 = j;
            i ++;
            j ++;
        }
        else if(suma < sumb){
            i ++;
        }
        else{
            j ++;
        }
    }
    ans = a.size() + b.size() - 2 * cur - 2;
    cout << ans << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T --){
        cin >> n >> m;
        a.resize(n + 1);b.resize(m + 1);prea.resize(n + 1, 0);preb.resize(m + 1, 0);
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            prea[i] = prea[i - 1] + a[i];
        }
        for(int i = 1;i <= m;i ++){
            cin >> b[i];
            preb[i] = preb[i - 1] + b[i];
        }
        if(prea[n] != preb[m]) cout << -1 << endl;
        else solve();
    }
    return 0;
}