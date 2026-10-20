#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

string lane;
int n, m;
vector<int> p;
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> lane;
    p.resize(n + 1, -1);
    q.push(0);
    p[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == n - 1)break;

        for(int i = u + 1; i <= min(n - 1, u + m);i ++){
            if(lane[i] == '1' && p[i] == -1){
                p[i] = p[u] + 1;
                q.push(i);
            }
        }
    }

    cout << p[n - 1] << endl; 

    return 0;
}