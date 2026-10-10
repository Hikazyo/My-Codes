#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), d(n + 1);
    a[0] = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }

    for(int i = 1;i <= m;i ++){
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c;
        d[r + 1] -= c;
    }

    for(int i = 1;i <= n;i ++){
        a[i] = a[i - 1] + d[i];
        cout << a[i] << ' ';
    }
    return 0;
}