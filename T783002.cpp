// Problem: T783002 过去
// Contest: Luogu - 【LGR-295-Div.2】洛谷 7 月月赛 III & FDOI Round 2 - 泠
// URL: https://www.luogu.com.cn/problem/T783002?contestId=330173
// Memory Limit: 16 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int we = 0;
    for(int i = 1;i <= n;i++){
        int w;
        cin >> w;
        if(i == 1)we = w;
        ans += w;
    }
    cout << ans - we + 1 << endl;
    return 0;
}