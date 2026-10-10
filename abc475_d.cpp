#include <bits/stdc++.h>
using namespace std;

vector<int> getPattern(const string& s) {
    int mp[128];
    fill(mp, mp + 128, -1);
    vector<int> pat;
    int nxt = 0;
    for (char c : s) {
        if (mp[(int)c] == -1) mp[(int)c] = nxt++;
        pat.push_back(mp[(int)c]);
    }
    return pat;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    vector<int> patS = getPattern(S);

    const int MAXP = 10000000;
    vector<bool> isPrime(MAXP, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXP; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXP; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int low = 1;
    for (int i = 1; i < n; i++) low *= 10;
    int high = low * 10;

    for (int p = low; p < high; p++) {
        if (!isPrime[p]) continue;
        string T = to_string(p);
        if (getPattern(T) == patS) {
            cout << p << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}