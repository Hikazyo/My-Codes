#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, q;
int pr[4] = {2, 3, 5, 7};

struct tree{
    ll mx, add;
}tr[4][4 * N];

void build(int k, int node, int l, int r) {
    tr[k][node].mx = 0; 
    tr[k][node].add = 0;
    if(l == r)return;
    int mid = (l + r) >> 1;
    build(k, node << 1, l, mid);
    build(k, node << 1 | 1, mid + 1, r);
}

void SpreadLazy(int k, int node) {
    ll a = tr[k][node].add;
    tr[k][node << 1].mx += a;
    tr[k][node << 1].add += a;
    tr[k][node << 1 | 1].mx += a;
    tr[k][node << 1 | 1].add += a;
    tr[k][node].add = 0;
}

void update(int k, int node, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
        tr[k][node].mx += v;
        tr[k][node].add += v;
        return;
    }
    SpreadLazy(k, node);
    int mid = (l + r) >> 1;
    if (x <= mid) update(k, node << 1, l, mid, x, y, v);
    if (y > mid) update(k, node << 1 | 1, mid + 1, r, x, y, v);
    tr[k][node].mx = max(tr[k][node << 1].mx, tr[k][node << 1 | 1].mx);
}

ll query(int k, int node, int l, int r, int x, int y) {
    if(x <= l && r <= y)
        return tr[k][node].mx;
    SpreadLazy(k, node);
    int mid = (l + r) >> 1;
    ll ans = -1;
    if(x <= mid)ans = max(ans, query(k, node << 1, l, mid, x, y));
    if(y > mid)ans = max(ans, query(k, node << 1 | 1, mid + 1, r, x, y));
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int k = 0; k < 4; ++k) build(k, 1, 1, n);

    string op;
    while (q--) {
        cin >> op;
        if(op == "MULTIPLY"){
            int l, r, x;
            cin >> l >> r >> x;
            for(int k = 0; k < 4; ++k){
                int e = 0, t = x;
                while(t % pr[k] == 0){
                    t /= pr[k];
                    ++e;
                }
                if(e != 0)update(k, 1, 1, n, l, r, e);
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            ll best = 0;
            for(int k = 0; k < 4; ++k)
                best = max(best, query(k, 1, 1, n, l, r));
            cout << "ANSWER " << best << endl;
        }
    }
    return 0;
}
