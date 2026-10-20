// Problem: F - GCD Maximum Spanning Tree
// Contest: AtCoder - AtCoder Beginner Contest 469
// URL: https://atcoder.jp/contests/abc469/tasks/abc469_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct S{
    vector<int> par, sz;
    S(int n) : par(n), sz(n, 1){
        for(int i = 0;i < n;++i)par[i] = i;
    }
    int find(int x){
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    int maxA = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(A[i] > maxA)maxA = A[i];
    }

    vector<vector<int> > bucket(maxA + 1);
    for(int i = 0;i < N;++i)
        bucket[A[i]].push_back(i);

    S dsu(N);
    ll ans = 0;

    for(int d = maxA; d >= 1; --d){
        int first = -1;
        for(int m = d; m <= maxA; m += d){
            const vector<int> &v = bucket[m];
            for(int j = 0; j < v.size();++j){
                int idx = v[j];
                if(first == -1){
                    first = idx;
                }else{
                    if (dsu.unite(first, idx))
                        ans += d;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
