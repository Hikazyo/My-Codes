#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> p, c;

int bit(int n){
    int M = 1;
    while(M <= n)M <<= 1;
    M --;
    return M
}

void solve(int x){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while(n --){
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}
