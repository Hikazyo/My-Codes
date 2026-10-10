// Problem: T782491 未来
// Contest: Luogu - 【LGR-295-Div.2】洛谷 7 月月赛 III & FDOI Round 2 - 泠
// URL: https://www.luogu.com.cn/problem/T782491?contestId=330173
// Memory Limit: 512 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MAXV = 1 << 8;  

int mino(int L, int w){
	int k = 32 - __builtin_clz(L); 
    if(w == 0)return 0;
    if(L == 0)return INF; 
    if(w <= L)return 1;               
    if(w < (1 << k))return 2;        
    return INF;                         
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<int> R(n), C(m);
        for(int i = 0;i < n;i++)cin >> R[i];
        for(int j = 0;j < m;j++)cin >> C[j];

        vector<vector<int>> A(n, vector<int>(m));
        for(int i = 0;i < n; i++)
            for(int j = 0;j < m;j++)cin >> A[i][j];

        bool op = true;
        for(int i = 0;i < n && op;i++)
            for(int j = 0;j < m && op;j++)
                if(A[i][j] != (A[i][0] ^ A[0][j] ^ A[0][0]))op = false;
        if(!op){
        	cout << -1 << endl;
         	continue; 
        }


        int ANS = INF;
        for(int v = 0;v < MAXV;v++){
            ll cost = 0;
            bool gd = true;
            for(int i = 0;i < n;i++){
                int ri = v ^ A[i][0] ^ A[0][0];
                int c = mino(R[i], ri);
                if(c >= INF){
                	gd = false;
                	break;
                }
                cost += c;
            }
            if(!gd)continue;
            for(int j = 0;j < m;j++){
                int cj = v ^ A[0][j];
                int c = mino(C[j], cj);
                if(c >= INF){
                	gd = false;
                	break;
                }
                cost += c;
            }
            if(gd)ANS = min(ANS, (int)cost);
        }

        cout << (ANS >= INF ? -1 : ANS) << endl;
    }
    return 0;
}
