#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;

void solve(int n, string a){
    vector<bool> vis(n + 2, false);
    stack<int> k;
    int ans = 0, r = a.length()
    for(int i = 0;i < r;i ++){
        if(a[i] == '1'){    
            k.push(i + 1);
        }
        else if(a[i] == '2'){
            if(!k.empty()){
                vis[i + 1] = true;
                ans ++;
            }
            else{
                int x = k.top();
                vis[x] = true;
                k.pop();
                ans ++;
            }
        }
        else{
            vis[i + 1] = true;
            ans ++;
        }
    }
    cout << ans << endl;
    for(int i = 1;i <= n;i ++)
        if(vis[i])cout << i << ' '; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T --){
        int a;
        string k;
        cin >> a >> k;
        solve(a, k);
    }

    return 0;
}