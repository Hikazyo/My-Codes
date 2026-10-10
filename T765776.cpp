// Problem: T765776  「MSOI R1」回响
// Contest: Luogu - 【LGR-292-Div.3】洛谷基础赛 #37 & MSOI Round 1
// URL: https://www.luogu.com.cn/problem/T765776?contestId=325521
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    string ans;
    for(int k = 0; k < n; k++){
        int len = n - k;
        if(k % 2 == 0){
            ans += s.substr(0, len);
        }else{
            string sub = s.substr(n - len, len);
            reverse(sub.begin(), sub.end());
            ans += sub;
        }
    }
    cout << ans << endl;
    return 0;
}

//abcde abcde a  b  c   de abcde abcde
//abcde edcb abc ed a
