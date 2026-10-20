#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, c;
vector<ll> a;
ll ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    a.resize(n + 1);
    for(int i = 1;i <= n;i ++)cin >> a[i];
    sort(a.begin() + 1, a.end());
    
    for(int i = 1;i <= n;i ++){
        ll t = a[i] + c;
        ans += (upper_bound(a.begin() + 1, a.end(), t) - lower_bound(a.begin() + 1, a.end(), t));    
    }
    cout << ans << endl;
    return 0;
}