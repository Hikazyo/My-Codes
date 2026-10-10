#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

vector<int> al;
struct op{
    char c;
    int x;
};
vector<op> a;

int find(int x){
    int l = 0, r = al.size() - 1;
    int ans = -1;
    while(l <= r){
        int mid =(l + r) >> 1;
        if(al[mid] >= x){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        al.clear();
        a.clear();
        a.resize(n);
        
        for(int i = 0; i < n; i++){
            char c;
            int x;
            cin >> c >> x;
            al.push_back(x);
            a[i] = {c, x};
        }    
        sort(al.begin(), al.end());
        al.erase(unique(al.begin(), al.end()), al.end());
        int m = al.size();
        
        vector<int> l_push(m + 2, -1);
        vector<int> expire(n, -1);
        for(int i = 0; i < n; i++){
            int fx = find(a[i].x);
            if(a[i].c == '+')l_push[fx] = i;
            else if(a[i].c == 'T')expire[l_push[fx]] = i;  
        }
        
        stack<int> s;
        string ans;
        for(int i = 0; i < n; i++){
            if(a[i].c == '+'){
                s.push(i);
                ans += '+';
            }
            else ans += '?';
            while(!s.empty() && expire[s.top()] <= i){
                ans += '-';
                s.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}