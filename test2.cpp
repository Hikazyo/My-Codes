#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int mu[MAXN];            // 莫比乌斯函数
int dfn[MAXN], tout[MAXN], sz[MAXN], parent[MAXN];

// 线性筛求莫比乌斯函数
void build_mu(int n) {
    static vector<int> primes;
    static int lp[MAXN];
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) { lp[i] = i; primes.push_back(i); mu[i] = -1; }
        for (int p : primes) {
            if (p > lp[i] || 1LL * i * p > n) break;
            lp[i * p] = p;
            mu[i * p] = (i % p == 0) ? 0 : -mu[i];
        }
    }
}

int main() {
    build_mu(MAXN - 1);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        // ---------- 存图 ----------
        vector<vector<int> > g(n + 1);
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // ---------- 迭代 DFS：求 dfn、parent、sz、tout ----------
        vector<int> order;          // 先序遍历顺序
        order.reserve(n);
        vector<int> st;
        st.push_back(1);
        parent[1] = 0;
        int timer = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            dfn[u] = ++timer;
            order.push_back(u);
            for (int v : g[u]) {
                if (v == parent[u]) continue;
                if (dfn[v]) continue;
                parent[v] = u;
                st.push_back(v);
            }
        }

        for (int i = 1; i <= n; i++) sz[i] = 1;
        for (int i = n - 1; i >= 0; i--) {          // 逆序累加子树大小
            int u = order[i];
            if (parent[u] != 0) sz[parent[u]] += sz[u];
        }
        for (int i = 1; i <= n; i++) tout[i] = dfn[i] + sz[i] - 1;

        // ---------- 每个节点的儿子区间（按 dfn 升序）+ noGroup 标记 ----------
        vector<vector<int> > child(n + 1);
        for (int u = 2; u <= n; u++) child[parent[u]].push_back(u);

        vector<vector<int> > cStarts(n + 1), cEnds(n + 1);
        vector<char> noGroup(n + 1, 1);   // 儿子全是叶子则不必分组
        for (int u = 1; u <= n; u++) {
            sort(child[u].begin(), child[u].end(),
                 [](int a, int b) { return dfn[a] < dfn[b]; });
            for (int c : child[u]) {
                if (sz[c] > 1) noGroup[u] = 0;
                cStarts[u].push_back(dfn[c]);
                cEnds[u].push_back(tout[c]);
            }
        }

        // ---------- bucket[m]：所有能被 m 整除的点的 dfn（排序）----------
        vector<vector<int> > bucket(n + 1);
        for (int m = 1; m <= n; m++)
            for (int v = m; v <= n; v += m)
                bucket[m].push_back(dfn[v]);
        for (int m = 1; m <= n; m++)
            sort(bucket[m].begin(), bucket[m].end());

        // ---------- 统计答案 ----------
        ll ans = 0;
        for (int d = 1; d <= n; d++) {
            vector<int> &S = cStarts[d];   // 儿子 dfn（升序）
            int dc = (int)S.size();
            vector<int> cnt(dc, 0);
            int L = dfn[d], R = tout[d];

            for (int k = 1; k <= n / d; k++) {
                if (mu[k] == 0) continue;          // μ(k)=0 无贡献
                int m = k * d;
                vector<int> &vec = bucket[m];

                // X = 子树 d 内能被 m 整除的点数
                int X = (int)(upper_bound(vec.begin(), vec.end(), R)
                            - lower_bound(vec.begin(), vec.end(), L));
                if (X < 2) continue;

                ll separated;
                if (noGroup[d]) {
                    // 儿子都是叶子：同一儿子里不可能有两个点，无需分组
                    separated = 1LL * X * (X - 1) / 2;
                } else {
                    // 把每个点（除 d 自己）分到它所属的儿子子树
                    for (int t : vec) {
                        if (t < L || t > R) continue;
                        if (t == dfn[d]) continue;
                        int pos = (int)(upper_bound(S.begin(), S.end(), t)
                                      - S.begin()) - 1;
                        if (pos >= 0 && pos < dc && t <= cEnds[d][pos]) cnt[pos]++;
                    }
                    // 减去"同一个儿子子树内"的对（它们会提前汇合）
                    ll same = 0;
                    for (int i = 0; i < dc; i++)
                        if (cnt[i]) {
                            same += 1LL * cnt[i] * (cnt[i] - 1) / 2;
                            cnt[i] = 0;
                        }
                    separated = 1LL * X * (X - 1) / 2 - same;
                }
                ans += (ll)mu[k] * separated;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
