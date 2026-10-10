#include<bits/stdc++.h>
using namespace std;
int ans = 0, decr = 0; ;
double p, n, m;

int main(){
    cin >> n >> m >> p;
    for(int i = 1;i <= n;i ++){
        int d, v;
        cin >> d >> v;
        if(d <= m){
            ans += v;
            decr += v * (1 - (p / 100));
            // cout << decr << endl;
        }
    }
    cout << ans - decr << endl;

    return 0;
}