#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll W, ans = 0;
vector<ll>a, b;

void dfs(int u, ll w, ll cur){
    if(w > W)return;
    if(u == n){
        if(cur > ans)ans = cur;
        return;
    }
    dfs(u + 1, w + b[u], cur + a[u]);
    dfs(u + 1, w, cur);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> W;
    a.resize(n + 1);b.resize(n + 1);
    for(int i = 0;i < n;i ++)
        cin >> a[i] >> b[i];
    
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
