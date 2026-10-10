#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans = 0;
vector<ll> k;

ll find(int a){
    if(a == 1)return 1;
    ll cur = 1;
    if(k[i] != 0){
        return k[a];
    }
    for(int i = 1;i <= a / 2;i ++)
        cur += find(i);
    return cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    k.resize(1001, 0);
    cout << k[n] << endl;
    return 0;
}