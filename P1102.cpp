#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c;
vector<ll> a;
ll ans = 0;

ll find(ll l, ll r){
    int al = 1, ar = n;
    int cnt = 0;
    while(al <= ar){
        int mid = (al + ar) >> 1;
        if(l == r + c){
            cnt ++;
            al = mid + 1;
        }
        else{
            ar = mid - 1;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    a.resize(n + 1);
    for(int i = 1;i <= n;i ++ )cin >> a[i];
    sort(a.begin() + 1, a.end());
    for(int i = 1;i <= n;i ++){
        for(int j = i + 1;j <= n;j ++){
            ans += find(a[i], a[j]);
        }
    }

    cout << ans << endl;
    return 0;
}