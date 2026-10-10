#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;
    vector<ll> s(n + 1, 0), c(n + 2, 0); 
    for(int i = 1; i <= n;i ++){
        cin >> s[i];
        c[i] = s[i] - s[i - 1];
    }
    for(int i = 1;i <= p;i ++){
        int l, r, z;
        cin >> l >> r >> z;
        c[l] += z;
        c[r + 1] -= z;
    }
    for(int i = 1;i <= n;i ++)s[i] = s[i - 1] + c[i];
    sort(s.begin() + 1, s.end());
    //for(int i = 1;i <= p;i ++)cout << s[i] << ' ';
    cout << s[1] << endl;
    return 0;
}