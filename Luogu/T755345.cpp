// Problem: T755345 [ICPC 2017 Xi'an R] Lovers
// Contest: Luogu - [ICPC2017 Xi' an R] ICPC 2017 区域赛西安站重现赛
// URL: https://www.luogu.com.cn/problem/T755345?contestId=339238
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 1;
int a[M], b[M];
int main(){
	int T;
	cin >> T;
	while(T --){
		int N, K;
		cin >> N >> K;
		int ans = 0;
		for(int i = 1;i <= N;i ++)cin >> a[i];
		for(int i = 1;i <= N;i ++)cin >> b[i];
		sort(a + 1,a + N + 1);
		sort(b + 1,b + N + 1);
		int j = 1;                          
		for(int i = N; i >= 1; i--){ 
    		while(j <= N && b[j] < K - a[i])j++;
   			if(j <= N){
   				ans++;
   				j++; 
   			}      
		}
		cout << ans << endl;
	}
	return 0;
}