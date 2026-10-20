#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ans = -0x3f3f3f3f, cur = -0x3f3f3f3f;
    for(int i = 1;i <= n;i ++){
        ll x;
        cin >> x;
        cur = max(x, cur + x);
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}