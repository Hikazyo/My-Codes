#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int L = -1, R = -1;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i+1]) {
            if(L == -1) L = i;
            R = i + 1;
        }
    }

    if(L == -1) {
        cout << "Yes\n";
        return 0;
    }

    int len = R - L + 1;
    if(len > k) {
        cout << "No\n";
        return 0;
    }

    int start_min = max(1, R - k + 1);
    int start_max = min(L, n - k + 1);

    for(int i = start_min; i <= start_max; i++) {
        bool ok = true;
        
        for(int j = 1; j < i; j++) {
            if(a[j] > a[j+1]) { ok = false; break; }
        }
        if(!ok) continue;

        for(int j = i + k; j < n; j++) {
            if(a[j] > a[j+1]) { ok = false; break; }
        }
        if(!ok) continue;

        int mn = 1e9, mx = -1e9;
        for(int j = i; j <= i + k - 1; j++) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
        }

        if(i > 1 && a[i-1] > mn) ok = false;
        if(i + k <= n && mx > a[i+k]) ok = false;

        if(ok) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}