#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int n, m;
int k[N][20], lg2[N] = {0};
int main(){
    n = read();
    m = read();
    for(int i = 1;i <= n;i ++)cin >> k[i][0];

    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for(int i = 1;(1 << i) <= n;i ++)
        for(int j = 1;j + (1 << i) - 1 <= n;j ++)
            k[j][i] = max(k[j][i - 1], k[j + (1 << i - 1)][i - 1]);

    while(m --){
        int l = read(), r = read();
        int x = lg2[r - l + 1];
        cout << max(k[l][x], k[r - (1 << x) + 1][x]) << '\n';
    }

    return 0;
}