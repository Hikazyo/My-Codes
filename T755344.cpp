// Problem: T755344 [ICPC 2017 Xi'an R] XOR
// Contest: Luogu - [ICPC2017 Xi' an R] ICPC 2017 区域赛西安站重现赛
// URL: https://www.luogu.com.cn/problem/T755344?contestId=339238
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

const int B = 30;
const int N = 10005;

int basis[N][B];   
int pos[N][B];     

void insert(int i, int x){
    for(int b = 0; b < B; b++){
        basis[i][b] = basis[i-1][b];
        pos[i][b]   = pos[i-1][b];
    }
    int idx = i;
    for(int b = B-1; b >= 0; b--){
        if(x >> b & 1){
            if(!basis[i][b]){
                basis[i][b] = x;
                pos[i][b]   = idx;
                break;
            }
            if(pos[i][b] < idx){
                swap(x, basis[i][b]);
                swap(idx, pos[i][b]);
            }
            x ^= basis[i][b];
        }
    }
}

int query(int l, int r){
    int x = 0;
    for(int b = B-1; b >= 0; b--){
        if(pos[r][b] >= l && (x ^ basis[r][b]) > x)
            x ^= basis[r][b];
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--){
        int n, q, k;
        cin >> n >> q >> k;
        int mask = ~k;
        for(int i = 1; i <= n; i++){
            int val; cin >> val;
            insert(i, val & mask);
        }
        while(q--){
            int l, r; cin >> l >> r;
            cout << (k | query(l, r)) << '\n';
        }
    }
    return 0;
}
