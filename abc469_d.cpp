// Problem: D - The Big Two
// Contest: AtCoder - AtCoder Beginner Contest 469
// URL: https://atcoder.jp/contests/abc469/tasks/abc469_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int> > edges(M);
    for(int i = 0;i < M;++i){
        int a, b;
        cin >> a >> b;
        if(a > b)swap(a, b);
        edges[i] = make_pair(a, b);
    }

    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    int m = edges.size();

    vector<vector<int> >d(N + 1);
    vector<int> deg(N + 1, 0);
    for(int i = 0;i < m;++i){
        int a = edges[i].first;
        int b = edges[i].second;
        d[a].push_back(b);
        d[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    int max_d = 0;
    for(int i = 1; i <= N; ++i)
        if(deg[i] > max_d)max_d = deg[i];

    vector<int>fr(max_d + 1, 0);
    for(int i = 1;i <= N;++i)fr[deg[i]]++;

    ll na = 0;
    for(int x = 1; x <= N; ++x){
        int t = m - deg[x];
        if(t < 0 || t > max_d) continue;
        ll cnt = fr[t];
        if (deg[x] == t) cnt--;            
        for(int j = 0; j < (int)d[x].size(); ++j){
            int y = d[x][j];
            if (deg[y] == t) cnt--;
        }
        
        if (cnt > 0) na += cnt;
    }

    ll dv = 0;
    for(int i = 0; i < m; ++i){
        int a = edges[i].first;
        int b = edges[i].second;
        if ((ll)deg[a] + deg[b] - 1 == m)
            dv++;
    }

    ll ans = na / 2 + dv;
    cout << ans << endl;

    return 0;
}

