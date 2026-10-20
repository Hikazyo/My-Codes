#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        if(i % 2 == 1)sum += x;
    }
    cout << sum;
    return 0;
}
