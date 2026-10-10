#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
typedef long long ll;
const ll INF = 4e18;

vector<ll> pos[M];
pair<ll, int> xt[M];  // 位置用 ll，因为 x 可达 1e9，但差值可能更大
int idx[M];
ll a[M], rest[M];
ll nowpos, nowsum;

ll check(int i){
    if(idx[i] < (int)pos[i].size()) return pos[i][idx[i]];
    return INF;
}

void solve(){
    int n, m;
    cin >> n >> m;
    nowsum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        rest[i] = a[i];
        nowsum += a[i];
        pos[i].clear();
        idx[i] = 0;
    }
    for(int i = 1; i <= m; i++){
        cin >> xt[i].first >> xt[i].second;
        pos[xt[i].second].push_back(xt[i].first);
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    nowpos = 0;
    for(int i = 1; i <= n; i++) pq.push({check(i), i});

    for(int i = 1; i <= m; i++){
        ll x = xt[i].first;
        int t = xt[i].second;
        ll need = x - nowpos;

        if(nowsum < need){
            cout << nowpos + nowsum << '\n';
            return;
        }

        // 消耗 need 能量
        while(need > 0){
            auto cur = pq.top(); pq.pop();
            ll npos = cur.first;
            int id = cur.second;
            if(npos != check(id)) continue; // 过期信息

            ll take = min(rest[id], need);
            rest[id] -= take;
            nowsum -= take;
            need -= take;

            if(rest[id] > 0){
                // 没喝完，下一次充电位置不变，重新入队
                pq.push({check(id), id});
            }
            // 如果喝完了，暂时不入队，等充电后再入
        }

        // 到达补给站，给核心 t 充电
        if(idx[t] < (int)pos[t].size() && pos[t][idx[t]] == x){
            idx[t]++; // 移到下一个补给站
        }
        ll add = a[t] - rest[t];
        rest[t] = a[t];
        nowsum += add;
        // 重新入队，用新的下一次充电位置
        pq.push({check(t), t});

        nowpos = x;
    }

    // 所有补给站处理完
    cout << nowpos + nowsum << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}