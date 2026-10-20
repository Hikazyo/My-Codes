// Problem: T755351 [ICPC 2017 Xi'an R] Arrangement for Contests
// Contest: Luogu - [ICPC2017 Xi' an R] ICPC 2017 区域赛西安站重现赛
// URL: https://www.luogu.com.cn/problem/T755351?contestId=339238
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e6 + 1;
ll a[M];
int main(){
	int T;
	cin >> T;
	while(T --){
		int N, K;
		ll ans = 0;
		cin >> N >> K;
		for(int i = 1;i <= N;i ++)cin >> a[i];
		for(int i = 1;i <= N - K + 1;i ++){
			ll mn = 0x3f3f3f3f3f3f3f3f;
			for(int j = i;j <= i + K - 1;j ++)mn = min(mn, a[j]);
			for(int j = i;j <= i + K - 1;j ++)a[j] -= mn;
			ans += mn;
		}
		cout << ans << endl;
	}
	return 0;
}