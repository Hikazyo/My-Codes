#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

void solve(int x, int y){
    int ans = -1;
    if(x == y)cout << x << endl;
    else if(x > y){
        if((x + y) % 2 == 0)ans = x;
        else ans = x + 1;
        cout << ans << endl;
    }
    else{
        if(y == x + 1)ans = y;
        cout << ans << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while(n --){
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}
