#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int> > > colors(q + 1);

    for(int i = 0; i < q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        colors[x].push_back({l, r});
    }

    vector<int> diff(n + 2, 0);

    for (int x = 1; x <= q; x++) {
        if (colors[x].empty()) continue;

        auto &v = colors[x];
        sort(v.begin(), v.end());

        vector<pair<int, int>> merged;
        for (auto [l, r] : v) {
            if (merged.empty() || l > merged.back().second + 1) {
                merged.push_back({l, r});
            }
            else {
                merged.back().second = max(merged.back().second, r);
            }
        }

        for(auto [l, r] : merged){
            diff[l]++;
            diff[r + 1]--;
        }
    }

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        cout << cur << (i == n ? '\n' : ' ');
    }

    return 0;
}