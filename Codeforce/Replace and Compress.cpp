#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;

void solve(string a){
    int l = a.length();
    ll ans = 1;
    bool comb = false, me = false;
    for(int i = 1; i <= l - 2; i++){
        if(a[i-1] == a[i] && a[i] == a[i+1])
            comb = true;

        if(a[i-1] == a[i+1] && a[i-1] != a[i])
            me = true;
    }
    
    if(comb) ans++;
    if(me) ans++;
    
    cout << ans << endl;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T --){
        string a;
        cin >> a;
        solve(a);
    }
    return 0;
}