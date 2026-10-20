#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;

void solve(int a, int b){
    int ans = 0;
    if(b >= a){
        cout << -1 << endl;
        return;
    }
    if(b <= a / 2){
        ans = b;
    }
    else{
        ans = a - b;
    }
    cout << ans << endl;
    return ;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T --){
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}