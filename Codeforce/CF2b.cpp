#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int T, n, k;
vector<int> a, b, cnt1, cnt2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T --){
        cin >> n >> k;
        a.resize(n / 2 + 1);b.resize(n / 2 + 1);cnt1.resize(n + 1, 0);cnt2.resize(n + 1, 0);
        for(int i = 1;i <= n;i ++){
            int x;
            cin >> x;
            if(i % 2 == 0){
                a.push_back(x);
                cnt1[x] ++;
            }
            else{
                b.push_back(x);
                cnt2[x] ++;
            }
        }
        int mek1 = -1, mek2 = -1;
        for(int i = 1;i <= n;i ++)
            if(cnt1[i] < k){
                mek1 = i;
                break;
            }
        for(int i = 1;i <= n;i ++)
            if(cnt2[i] < k){
                mek2 = i;
                break;
            }
        if(mek1 != mek2)cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
