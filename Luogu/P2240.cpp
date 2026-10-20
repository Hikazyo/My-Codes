#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t;
struct g{
    ll m, v;
    double avg;
};
vector<g> a;

bool cmp(const g& x, const g& y){
    return x.avg > y.avg;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    a.resize(n + 1);
    for(int i = 1;i <= n;i ++){
        cin >> a[i].m >> a[i].v;
        a[i].avg = ( a[i].v * 1.0 ) / (a[i].m * 1.0);
    }

    sort(a.begin() + 1, a.end(), cmp);
    double ans_val = 0;
    int cur_mass = 0, cnt = 1;
    while(cur_mass <= t && cnt <= n){
        if(a[cnt].m > t - cur_mass){
            ans_val += (t - cur_mass) * a[cnt].avg;
            break;
        }
        else{
            ans_val += a[cnt].v;
            cur_mass += a[cnt].m;
            cnt ++;
        }
    }
    cout << fixed <<setprecision(2) << ans_val << endl;
    return 0;
}