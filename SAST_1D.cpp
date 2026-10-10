#include<bits/stdc++.h>
using namespace std;

int n, col, T;
vector<vector<int> > tree, up;
vector<int> dep, gcdd, lcaa;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a; 
}

void dfs(int u, int p){
    up[0][u] = p;
    for(int i = 1;i <= g[u];i ++){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

void build(int r){
    col = 1;
    while((1 << col) <= n)col ++;
    up.assign(col, vector<int>(n + 1, 0));
    dep.assign(n + 1, 0);

    dfs(r, 0);

    for(int i = 1;i < col;i ++)
        for(int j = 1;j <= n;j ++)
            up[i][j] = up[i - 1][up[i - 1][j]];
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);

    if dif = dep[u] - dep[v];
    for(int i = 0;i < col;i ++){
        if(dif & (1 << i))
            u = up[i][u];

    }

    for(int i = col - 1;i >= 0;i --){
        if(up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }

    return up[0][u];
}

void solve(int m){
    int ans = 0;
    tree.assign(n + 1, {});
    for(int i = 0;i < m - 1;i ++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
        int cnt = 1;
    }

    int r = 1;
    build(r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T --){
        cin >> n;
        gcdd.resize(n + 1, 0);
        lcaa.resize(n + 1, 0);
        solve(n);
    }
    return 0;
}