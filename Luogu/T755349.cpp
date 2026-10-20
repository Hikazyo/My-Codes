// Problem: T755349 [ICPC 2017 Xi'an R] God of Gamblers
// Contest: Luogu - [ICPC2017 Xi' an R] ICPC 2017 区域赛西安站重现赛
// URL: https://www.luogu.com.cn/problem/T755349?contestId=339238
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int main(){
	float a, b;
	while(~scanf("%f %f",&a,&b))printf("%.5f\n",a / (a + b));
	return 0;
}