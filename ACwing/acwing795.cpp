#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int a[M], d[M];

int main(){
    int n, m;
    cin >> n >> m;
    d[0] = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        d[i] = d[i - 1] + a[i];        
    }
    for(int i = 1;i <= m;i ++){
        int l, r;
        cin >> l >> r;
        cout << d[r] - d[l - 1] << endl;
    }
    return 0;
}