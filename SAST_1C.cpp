#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct keys{
    ll a, b, c;
    ll L, R;
};

vector<keys> k;
int n;
ll W;
ll ans = 0;
vector<int> num, rk, pk;
vector<ll> pref;
ll bestp = -1, bestq = -1, bestmid = 0;

bool cmp(int x, int y) {
    return k[x].a < k[y].a;
}

ll find(int p, int q, int mid){
    if(mid == 0) return 0;

    int x = min(n, mid + 2);
    ll sum = pref[x];
    int cnt = 0;

    if(rk[p] <= x){
        sum -= k[p].a;
        cnt ++;
    }
    if(rk[q] <= x){
        sum -= k[q].a;
        cnt ++;
    }

    int remove = (x - cnt) - mid;
    int pos = x;
    while(remove > 0 && pos >= 1){
        int id = num[pos];
        if(id != p && id != q){
            sum -= k[id].a;
            remove--;
        }
        pos --;
    }
    return sum;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> W;
    k.resize(n + 1);
    num.resize(n + 1, 0);
    rk.resize(n + 1, 0);
    pref.resize(n + 1, 0);
    pk.resize(n + 1, 0);
    for(int i = 1;i <= n;i ++){
        cin >> k[i].a >> k[i].b >> k[i].c;
        k[i].L = max(k[i].c, k[i].a - k[i].b - k[i].c);
        k[i].R = min(k[i].b + k[i].c ,k[i].a - k[i].c);
    }
    
    iota(num.begin(), num.end(), 0);
    sort(num.begin() + 1, num.end(), cmp);
    
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + k[num[i]].a;
    for(int i = 1; i <= n; i++) rk[num[i]] = i;

    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(i == j) continue;

            ll C = W + k[i].L - k[j].R - k[i].a;
            if(C < 0)continue;

            int lo = 0, ro = n - 2;
            int bmid = 0;
            while(lo <= ro){
                int mid = (lo + ro) >> 1;
                ll sim = find(i, j, mid);
                if(sim <= C){
                    bmid = mid;
                    lo = mid + 1;
                }
                else{
                    ro = mid - 1;
                }
            }

            int total = 2 + bmid;
            if(total > ans){
                ans = total;
                bestp = i;
                bestq = j;
                bestmid = bmid;

                pk.clear();
                int cnt = 0;
                for(int o = 1; o <= n; o++){
                    int id = num[o];
                    if(id == i || id == j) continue;
                    pk.push_back(id);
                    cnt ++;
                    if (cnt == bmid) break;
                }
            }
        }
    }
    
    cout << ans << endl;
    if(ans == 0){
        cout << endl;
        return 0;
    }
    if(ans == 1){
        cout << bestp << endl;
        return 0;
    }
    vector<int> out;

    if (k[bestp].L == k[bestp].c){//第一
        out.push_back(bestp);
    }
    else{
        out.push_back(-bestp);
    }

    for(int i = 0;i < (int)pk.size();i ++)out.push_back(pk[i]);//中间

    if(k[bestq].R == k[bestq].b + k[bestq].c){//最后
        out.push_back(bestq);
    }
    else{
        out.push_back(-bestq);
    }

    for(int i = 0; i < (int)out.size(); i++) {
        if(i) cout << " ";
        cout << out[i];
    }
    cout << endl;

    return 0;
}