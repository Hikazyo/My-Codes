#include<bits/stdc++.h>
using namespace std;
const int M = 3e5 + 1;
int a[M];
typedef long long ll;

int main(){
    int N;
    cin >> N;
    for(int i = 1;i <= N;i ++)
        cin >> a[i];
        if(a[N] == a[N - 1] + 1){
            ll ans = a[N - 1] - (N - 2);
            if(ans % 2 == 0)cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
        else{
        cout << "Alice" << endl;
    }
    return 0;
}