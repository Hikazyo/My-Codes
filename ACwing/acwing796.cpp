#include<bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
int a[M][M], d[M][M];

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    d[0][0] = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> a[i][j];
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + a[i][j];
        }
    }

    for(int i = 1;i <= q;i ++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1] << endl;
    }

    return 0;
}