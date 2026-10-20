#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, ap;
vector<int>p, h;

int find(int x){
    if(p[x] == x){
        return x;
    }
    else{
        return p[x] = find(p[x]);
    }
}

void unite(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(h[rx] > h[ry]){
        p[ry] = rx;
    }   
    else if(h[rx] < h[ry]){
        p[rx] = ry;
    }
    else{
        p[rx] = ry;
        h[ry] ++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> ap;
    p.resize(n + 1);h.resize(n + 1, 1); 
    iota(p.begin(), p.end(), 0);

    for(int i = 1;i <= m;i ++){
        int l, r;
        cin >> l >> r;
        unite(l, r);
    }

    for(int i = 1;i <= ap;i ++){
        int x, y;
        cin >> x >> y;
        if(find(x) == find(y)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}