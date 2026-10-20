#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<ll> w, need;
ll cur = 0, sum = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    w.resize(n + 1);
    need.resize(m + 1);
    for(int i = 1;i <= n;i ++)cin >> w[i];
    for(int i = 1;i <= m;i ++){
        cin >> need[i];
        sum += need[i];
    }
    sort(w.begin() + 1, w.end());
    //for(int i = 1;i <= n;i ++)cout << w[i] << ' ';
    for(int i = n;i >= n + 1 - k;i --)cur += w[i];
    //cout << cur << ' ' << sum << endl;
    if(cur >= sum)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}