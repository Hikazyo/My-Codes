#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int n, k, time;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k >> time;
    vector<ll> t(n + 1, 0),sum(n + 1, 0);
    for(int i = 1;i <= n;i ++)
        cin >> t[i];
    sort(t.begin() + 1,  t.end());
    int cnt = 1;
    ll latest_r = t[1] + time, latest_l = t[1];
    for(int i = 1;i <= n;i ++){
        if(t[i] >= t[i - 1] && t[i - 1] + k >= t[i]){
            latest_r = max(latest_r, t[i] + k - t[i - 1]);
            latest_l = max(latest_l, t[i - 1]);
            sum[cnt] += latest_r - latest_l;
        }
        else{
            cnt ++;
        }
    }
    
    for(int i = 1;i <= cnt;i ++)cout << sum[i] << ' ';
    
    
    return 0;
}