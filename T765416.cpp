// Problem: T765416  「MSOI R1」距离
// Contest: Luogu - 【LGR-292-Div.3】洛谷基础赛 #37 & MSOI Round 1
// URL: https://www.luogu.com.cn/problem/T765416?contestId=325521
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> d(N + 1);
    for (int i = 1;i < N;++i)cin >> d[i];
    vector<int> t(N + 1);
    for(int i = 1;i <= N;++i)cin >> t[i];

    vector<ll> p(N + 1, 0);
    for(int i = 2;i <= N;++i)p[i] = p[i - 1] + d[i - 1];
    ll ans = 0;
    int lz = -1;

    for(int i = 1;i <= N;++i){
        if(t[i] == 0){
            if(lz != -1){
                int L = lz;
        	    int R = i;
                int k = R - L;  
                for(int j = 1;j < k;++j){
                    __int128 l  = (__int128)k * (p[L + j] - p[L]);
                    __int128 r = (__int128)j * (p[R] - p[L]);
                    if(l != r){
                        ++ans;
                    }
                }
            }
            lz = i;
        }
    }

    cout << ans << endl;
    return 0;
}