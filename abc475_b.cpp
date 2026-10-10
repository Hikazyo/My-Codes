#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    ll coin1 = 0, coin10 = 0, coin100 = 0;

    for (int i = 0; i < N; i++) {
        ll A;
        cin >> A;

        ll pay = ((A + 999) / 1000) * 1000; 

        ll change = pay - A;

        coin100 += change / 100;
        change %= 100;
        coin10 += change / 10;
        change %= 10;
        coin1 += change;
    }

    cout << coin1 << " " << coin10 << " " << coin100 << "\n";
    return 0;
}