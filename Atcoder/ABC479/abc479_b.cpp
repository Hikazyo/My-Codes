#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a;
    int ans = 0, cur = 0;
    for(int i = 0;i <= a.length();i ++){
        if(a[i] == 'R'){
            cur ++;
            ans = max(ans, cur);
        }
        else cur = 0;
    }
    cout << ans << endl;
    return 0;
}
