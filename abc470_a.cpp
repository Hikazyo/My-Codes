// Problem: A - Fizz
// Contest: AtCoder - JPRS Programming Contest 2026#2 (AtCoder Beginner Contest 470)
// URL: https://atcoder.jp/contests/abc470/tasks/abc470_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		if(i % 3 == 0)cout << "Fizz" << endl;
		else cout << i << endl;
	}
	return 0;
}