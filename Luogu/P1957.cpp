#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int op = 0;
    char k;
    cin >> n;
    while(n --){
        string ans;
        int a, b;
        
        cin >> k;
        if(k >= '0' && k <= '9'){
            cin.putback(k);
            cin >> a >> b;
        }
        else cin >> a >> b;
        
        switch(k){
            case 'a':
                op = 1;
                break;
            case 'b':
                op = 2;
                break;
            case 'c':
                op = 3;
                break;
        }
        int sum = a + b, de = a - b, po = a * b;
        string a1 = to_string(a), b1 = to_string(b), s1 = to_string(sum);
        string d1 = to_string(de), p1 = to_string(po);
        switch(op){
            case 1:
                ans = a1 + '+' + b1 + '=' + s1;
                break;
            case 2:
                ans = a1 + '-' + b1 + '=' + d1;
                break;
            case 3:
                ans = a1 + '*' + b1 + '=' + p1;
                break;
        }
        cout << ans << endl << ans.length() << endl;
    }
    return 0;
}