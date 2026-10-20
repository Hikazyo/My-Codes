#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 2;
typedef long long ll;

vector<ll> pos[M];
pair<int, int> xt[M];
ll idx[M], a[M], rest[M];
ll nowpos, nowsum;

ll check(int i){
    if(idx[i] < pos[i].size())return pos[i][idx[i]];
    return 0x3f3f3f3f;
}

void solve(){
    int n, m;
    cin >> n >> m;
    nowsum = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        rest[i] = a[i];
        nowsum += a[i];
        pos[i].clear();
        idx[i] = 0;
    }
    for(int i = 1;i <= m;i ++){
        cin >> xt[i].first >> xt[i].second;
        pos[xt[i].second].push_back(xt[i].first);
    }
    
    priority_queue<pair<ll,int>, vector< pair<ll,int> >, greater<pair<ll,int> > >pq;
    
    nowpos = 0;

    for (int i = 1; i <= n; i++)pq.push(pair<ll, int>(check(i), i));
    
    for(int i = 1;i <= m;i ++){
        ll x = xt[i].first, t = xt[i].second, need = x - nowpos;
        if(nowsum < need){
            cout << nowpos + nowsum << endl;
            return;
        }

        while(need > 0){
            pair<ll, int> c = pq.top();
            pq.pop();
            ll npos = c.first, id = c.second;

            if(npos != check(id) )continue;

            ll at = min(rest[id], need);
            rest[id] -= at;
            nowsum -= at;
            need -= at;

            if(rest[id] > 0)pq.push(pair<ll, int>(check(id), id));
        }
        if(idx[t] < pos[t].size() && pos[t][idx[t]] == x) idx[t] ++;

        ll add = a[t] - rest[t];
        rest[t] = a[t];      
        nowsum += add;

        pq.push(pair<ll, int>(check(t), t));

        nowpos = x;

    }
        
     cout << nowpos + nowsum << endl;
}

    /*while(total > 0){
        cnt ++;
        if(total - e[p[cnt].second] >= dis[cnt]){
            ans += dis[cnt];
            total -= dis[cnt];
        }
        else continue;
    }

    cout << ans << endl;*/


int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}