// Problem: P17232 [Algo Beat Contest 017 A] 串哈希
// Contest: Luogu - 【LGR-296-Div.3】洛谷基础赛 #38 & Algo Beat Contest 017
// URL: https://www.luogu.com.cn/problem/P17232?contestId=333459
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, s;
	cin >> n >> s;
	ll ans = s;
	for(int i = 1;i <= n;i ++){
		string a;
		cin >> a;
		if(a.find("kirai") != string::npos){
            if (s >= 0) s = 0;
        } 
        else if(a.find("daishuki") != string::npos)s += 2;
        else if (a.find("shuki") != string::npos)s += 1;
        else s--;
        
	}
	if(s > 0)cout << s - ans << endl;
	else cout << "shuki" << endl;
	return 0;
}