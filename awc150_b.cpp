#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5 + 1;
ll k[M] = { };
ll ans = 1;

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >>k[i];
        ans *= k[i];
    }

    cout << ans << endl;
    return 0;
}