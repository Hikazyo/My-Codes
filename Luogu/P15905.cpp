#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;

struct animal{
    string name;
    ll val;
};
vector<animal> k;
int n, pmaxid = 0;
ll pmax = -INF, ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    k.resize(n + 1);
    for(int i = 1;i <= n;i ++){
        cin >> k[i].name >> k[i].val;
        if(k[i].name == "pig"){
            if(k[i].val > pmax){
                pmax = k[i].val;
                pmaxid = i;
            }
        }
    }

    ans += pmax;
    for(int i = 1;i <= n;i ++){
        if(i == pmaxid)continue;
        else{
            if(k[i].name != "pig"){
                if(k[i].val >= pmax)continue;
                else ans += k[i].val;
            }
        }
    }
    cout << ans << endl;

    return 0;
}