#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans = 0, s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    ll cur = 0;
    for(int i = 1;i <= n;i ++){
        int w;
        cin >> w;
        cur += w;
        if(cur >= s){
            ans ++;
            cur = 0;
        }
        
    }
    cout << ans << endl;
    return 0;
}