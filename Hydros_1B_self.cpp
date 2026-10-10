#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct zywoo{
    ll w, l, r;
};

int n;
ll ans = 0, m;
vector<ll> prel, prer, prew, prelv;
vector<ll> ltime, lv;
vector<int> v;

bool cmp(const zywoo& a, const zywoo& b){
    return a.w > b.w;
}

ll find(int a, ll T){
    int al = 1, ar = a;
    ll nans = ar;
    while(al <= ar){
        int mid = (al + ar) >> 1;
        if(prer[mid] - prel[mid] >= T){
            nans = mid;
            ar = mid - 1;
        }
        else{
            al = mid + 1;
        }
    }
    return nans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<zywoo> k(n + 1);
    for(int i = 1;i <= n;i ++)cin >> k[i].w >> k[i].l >> k[i].r;

    prel.resize(n + 1, 0);
    prer.resize(n + 1, 0);
    prew.resize(n + 1, 0);
    prelv.resize(n + 1, 0);
    ltime.resize(n + 2, 0); 
    lv.resize(n + 2, 0);
    sort(k.begin() + 1, k.end(), cmp);

    for(int i = 1; i <= n;i ++){
        prel[i] = prel[i - 1] + k[i].l;
        prer[i] = prer[i - 1] + k[i].r;
        prew[i] = prew[i - 1] + k[i].w * k[i].r;
        prelv[i] = prelv[i - 1] + k[i].w * k[i].l;
    }
    for(int i = n;i >= 1;i --){
        ltime[i] = ltime[i + 1] + k[i].l;
        lv[i] = lv[i + 1] + k[i].l * k[i].w;
    }

    for(int i = 1;i <= n;i ++){
        ll T = m - ltime[i + 1];
        ll nowsum = lv[i + 1];
        if(T >= prer[i - 1]){
            nowsum += prew[i - 1] + (T - prer[i - 1]) * k[i].w;
        }
        else{
            ll ex = T - prel[i - 1];
            int now = find(i - 1, ex);
            ll t = prer[now - 1] - prel[now - 1]; 
            nowsum += prew[now - 1] + k[now].w * (k[now].l + ex - t) + (prelv[i - 1] - prelv[now]);
        }
        ans = max(ans, nowsum);
    }

    cout << ans << endl;

    return 0;
}