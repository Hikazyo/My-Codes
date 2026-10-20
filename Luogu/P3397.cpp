#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > p;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    p.resize(n + 2, vector<int>(n + 2, 0));
        
    for(int i = 1;i <= m;i ++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p[x1][y1] += 1;
        p[x1][y2 + 1] -= 1;
        p[x2 + 1][y1] -= 1;
        p[x2 + 1][y2 + 1] += 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}