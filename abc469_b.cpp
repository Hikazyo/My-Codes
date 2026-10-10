// Problem: B - Isolated Seats
// Contest: AtCoder - AtCoder Beginner Contest 469
// URL: https://atcoder.jp/contests/abc469/tasks/abc469_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int M = 1e3;
char a[M];
int main(){
	int n, ans = 0;
	cin >> n ;
	for(int i = 1;i <= n; i++)cin >> a[i];
	a[0] = a[n + 1] = 'x';
	for(int i = 1;i <= n; i++)
		if( a[i] == 'x' &&  a[i - 1] == 'x' && a[i + 1] == 'x')ans ++;
	cout << ans << endl;
	return 0;
}