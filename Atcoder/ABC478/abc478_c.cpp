#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int>a(n + 1, 0);
    vector<bool> ke(n + 1, false);
    int kmin = 0, kmax = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(a[i - 1] >= a[i]){
            ke[i] = true;
            kmin = min(i, kmin);
            kmax = max(i, kmax);
        }
    }

    int len = kmax - kmin;
    if(len > k){
        cout << "No" << endl;
        return 0;
    }
    sort(a.begin() + kmin + 1, a.begin() + kmax + 1 );
    int la = a[kmin], ra = a[kmax];
    if(a[kmin - 1] > a[kmin] && a[kmax + 1] < a[kmax])
        cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}