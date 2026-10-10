#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int N, M, ans = 0;
int car[MAXN];
bool p[MAXN] = {true};

int main(){
    cin >> N >> M;
    for(int i = 1;i <= N;i ++){
        cin >> car[i];
        if(p[i]){
            ans ++;
        }
        else if(p[i + 1]){
            ans ++;
        }
        else continue;
    }

    cout << ans << endl;
    return 0;
}

