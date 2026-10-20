// Problem: B - Monocolor
// Contest: AtCoder - JPRS Programming Contest 2026#2 (AtCoder Beginner Contest 470)
// URL: https://atcoder.jp/contests/abc470/tasks/abc470_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a[101],b[101] = {};
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		b[a[i]]++;
	}
	int maxn = 0;
	for(int i = 1;i <= n;i ++)maxn = max(maxn,b[i]);
	cout << n - maxn << endl;
	return 0;
}