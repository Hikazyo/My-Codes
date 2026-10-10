// Problem: C - Cantrip
// Contest: AtCoder - AtCoder Beginner Contest 469
// URL: https://atcoder.jp/contests/abc469/tasks/abc469_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;
    cin >> N >> S;

    vector<int> pos;
    for(int i = 0;i < N;i++)if(S[i] == 'x')pos.push_back(i + 1);
    
    int total = (int)pos.size();

    vector<int> pref(N + 1, 0);
    for(int i = 0;i < N;i++)pref[i + 1] = pref[i] + (S[i] == 'o' ? 1 : 0);
    
    for(int i = 1;i <= N;i++){
        int c = pref[i];
        if (c == 0)cout << i << endl;            
        else{
            int be = i - c;         
            int t = be + c;    
            if(t > total)cout << N << endl; 
            else cout << pos[t - 1] << endl; 
            }
    }
    

    return 0;
}
