#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, s, l;
    cin >> n >> s >> l;
    vector<ll> a(n + 1), pos(n + 1);
    a[0] = 0;
    for(int i = 1;i < n;i ++){
        cin >> a[i];
        pos[i] = pos[i - 1] + a[i];
    }

    ll ans = 0;
    
    for(int i = )
    return 0;
}