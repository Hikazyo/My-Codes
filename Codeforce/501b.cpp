#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

struct ss{
    string name;
    int id;
};

int n;
vector<ss>p;

int find(int x){
    if(p[x].id == x){
        return;
    }
    else{
        return p[x].id = find(p[x].id);
    }
}

void unit(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(h[rx] > h[ry]){
        h[ry] = rx;
    }
    else if(h[rx] < h[ry]){
        h[rx] = ry;
    }   
    else{
        h[ry] = rx;
        h[rx] ++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        string a, b;
        cin >> a >> b;
        unit(a, b);
    }

    

    return 0;
}