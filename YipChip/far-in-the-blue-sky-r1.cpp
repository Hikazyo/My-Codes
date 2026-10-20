#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e5 + 1;
int a[M], b[M];
int ans1 = 0, ans2 = 0;
int n;

bool check(int w){
    if(w > n)return true;
    ll sum = 0, min1;

    for(int i = 1;i <= w;i ++)sum += b[i];
    min1 = sum;
    for(int i = w + 1;i <= n;i ++){
        sum += b[i] - b[i - w];
        if(sum < min1)min1 = sum;
    }
    return min1 >= 4;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    
    int lm = 0;
    for(int i = 1;i <= n;i ++){
        if(a[i] > 0)lm ++;
        else lm = 0;
        ans1 = max(lm, ans1);
    }
   
    for (int i = 1; i <= n; i++) b[i] = 4 - a[i];

    int l = 1, r = n + 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
        ans2 = l - 1;
    }


    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}