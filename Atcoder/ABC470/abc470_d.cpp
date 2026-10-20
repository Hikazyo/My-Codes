// Problem: D - Inverse and Swap
// Contest: AtCoder - JPRS Programming Contest 2026#2 (AtCoder Beginner Contest 470)
// URL: https://atcoder.jp/contests/abc470/tasks/abc470_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> P(N + 1), iP(N + 1);
    for(int i = 1;i <= N;++i){
        cin >> P[i];
        iP[P[i]] = i;
    }

    bool opo = false;

    while(Q--){
        int t;
        cin >> t;
        if(t == 2) opo = !opo; 
        else{
            int x, y;
            cin >> x >> y;
            if (opo) {
                int a = iP[x], b = iP[y];
                swap(iP[x], iP[y]);
                swap(P[a], P[b]);
            } 
            else{
                int a = P[x], b = P[y];
                swap(P[x], P[y]);
                swap(iP[a], iP[b]);
            }
        }
    }
    if(opo){
	    for(int i = 1;i <= N;++i) {
	        if (i == N) cout << iP[i] << endl;
	        else        cout << iP[i] << ' ';
	    }
	} 
	else{
    	for(int i = 1;i <= N;++i) {
        	if(i == N) cout << P[i] << endl;
        	else cout << P[i] << ' ';
    	}
	}


    return 0;
}
