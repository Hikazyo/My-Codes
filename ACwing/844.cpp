#include<iostream>
using namespace std;

int p[10];   
int n;
bool vis[10] = {false};

void dfs(int u){
    if(u == n){
        for(int i = 0;i < n;i ++)cout << p[i] << ' ';
        cout << endl;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            p[u] = i;
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}

int main(){
    cin >> n;
    
    dfs(0);
    
    return 0;
}