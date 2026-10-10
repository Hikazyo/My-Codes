#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
const ll INF = 4e18;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int n, m;
int kmax[N][20], kmin[N][20], lg2[N] = {0};
int main(){
    n = read();
    m = read();
    for(int i = 1;i <= n;i ++){
        int x = read();
        kmax[i][0] = kmin[i][0] = x;
    }

    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for(int i = 1;(1 << i) <= n;i ++)
        for(int j = 1;j + (1 << i) - 1 <= n;j ++){
            kmax[j][i] = max(kmax[j][i - 1], kmax[j + (1 << i - 1)][i - 1]);
            kmin[j][i] = min(kmin[j][i - 1], kmin[j + (1 << i - 1)][i - 1]);
        }
    
        cout << endl;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cout << kmax[j][i] << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cout << kmin[j][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}