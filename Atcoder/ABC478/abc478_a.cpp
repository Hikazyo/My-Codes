#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>a(n + 1, 0);
    int cnt = m / n, l = m - cnt * n;
    for(int i = 1;i <= n;i ++){
        if(l > 0){
            cout << cnt + 1 << endl;
            l --;
        }
        else cout << cnt << endl;
    }
    return 0;
}