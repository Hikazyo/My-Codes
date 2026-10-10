#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 7;

inline ll read() {
    ll f = 1, x = 0;char ch;
    do {ch = getchar();if (ch == '-')f = -1;} while (ch > '9' || ch < '0');
    do {x = x * 10 + ch - '0';ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

struct Edge{
	int to, next;
}edge[MAXN << 2];

int head[MAXN], cnt;

inline void addedge(int u, int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n, m, w[MAXN], c[MAXN];
int siz[MAXN], id[MAXN];
int top[MAXN], dep[MAXN], fa[MAXN], son[MAXN], root[MAXN];

void dfs(int u){
	dep[u] = dep[fa[u]] + 1;
	siz[u] = 1;
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].to;
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs(v);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}

void dfsn(int u, int y){
	top[u] = y;
	id[u] = (++cnt);
	if(son[u]) dfsn(son[u], y);
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].to;
		if (v == son[u] || fa[u] == v) continue;
		dfsn(v, v);
	}
}

struct segment_tree{
	int l, r;
	ll sum, maxx;
}t[MAXN * 40];

void insert(int &p, int x, int l, int r, int v){
	if(!p) p = (++cnt);
	if(l == r){
		t[p].sum = t[p].maxx = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)
		insert(t[p].l, x, l, mid, v);
	else 
		insert(t[p].r, x, mid + 1, r, v);
	t[p].maxx = max(t[t[p].l].maxx, t[t[p].r].maxx);
	t[p].sum = t[t[p].l].sum + t[t[p].r].sum;
}

void delet(int p, int x, int l, int r){
	if(!p) return;
	if(l == r){
		t[p].maxx = t[p].sum = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)
		delet(t[p].l, x, l, mid);
	else 
		delet(t[p].r, x, mid + 1, r);
	t[p].maxx = max(t[t[p].l].maxx, t[t[p].r].maxx);
	t[p].sum = t[t[p].l].sum + t[t[p].r].sum;
}

void update(int p, int x, int l, int r, int v) {
	if(!p) 
		p = (++cnt);
	if(l == r){
		t[p].sum = t[p].maxx = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)
		update(t[p].l, x, l, mid, v);
	else 
		update(t[p].r, x, mid + 1, r, v);
	t[p].maxx = max(t[t[p].l].maxx, t[t[p].r].maxx);
	t[p].sum = t[t[p].l].sum + t[t[p].r].sum;
}

ll query_sum(int p, int l, int r, int x, int y){
	if(!p) return 0;
	if(x <= l && r <= y) 
		return t[p].sum;
	int mid = (l + r) >> 1;
	ll ans = 0;
	if(x <= mid) 
		ans += query_sum(t[p].l, l, mid, x, y);
	if(y > mid) 
		ans += query_sum(t[p].r, mid + 1, r, x, y);
	return ans;
}

ll query_max(int p, int l, int r, int x, int y){
	if(!p) return -1e9;
	if(x <= l && r <= y) return t[p].maxx;
	int mid = (l + r) >> 1;
	ll ans = -1e9;
	if(x <= mid)
		ans = max(ans, query_max(t[p].l, l, mid, x, y));
	if(y > mid)
		ans = max(ans, query_max(t[p].r, mid + 1, r, x, y));
	return ans;
}

ll get_sum(int p, int x, int y){
	ll ans = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) 
			swap(x, y);
		ans += query_sum(p, 1, n, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) 
		swap(x, y);
	ans += query_sum(p, 1, n, id[x], id[y]);
	return ans;
}

ll get_max(int p, int x, int y){
	ll ans = -1e9;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) 
			swap(x, y);
		ans = max(ans, query_max(p, 1, n, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) 
		swap(x, y);
	ans = max(ans, query_max(p, 1, n, id[x], id[y]));
	return ans;
}

void solve_c(int l, int r){
	delet(root[c[l]], id[l], 1, n);
	c[l] = r;
	insert(root[c[l]], id[l], 1, n, w[l]);
}

void solve_w(int l, int r){
	delet(root[c[l]], id[l], 1, n);
	w[l] = r;
	insert(root[c[l]], id[l], 1, n, w[l]);
}

void solve_s(int l, int r){
	printf("%lld\n", get_sum(root[c[l]], l, r));
}

void solve_m(int l, int r){
	printf("%lld\n", get_max(root[c[l]], l, r));
}

int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i ++ ){
		w[i] = read();
		c[i] = read();
	}
	for(int i = 1; i < n; i ++ ){
		int x = read();
		int y = read();
		addedge(x, y);
		addedge(y, x);
	}
	dfs(1); 
	cnt = 0; 
	dfsn(1, 1);
	for(int i = 1; i <= n; i ++ ) 
		insert(root[c[i]], id[i], 1, n, w[i]);
	for(int i = 1; i <= m; i ++ ){
		char opt[10];
		scanf("%s", opt);
		int l = read(), r = read();
		if(opt[1] == 'C') 
			solve_c(l, r);
		if(opt[1] == 'W') 
			solve_w(l, r);
		if(opt[1] == 'S') 
			solve_s(l, r);
		if(opt[1] == 'M') 
			solve_m(l, r);
	}
	return 0;
}