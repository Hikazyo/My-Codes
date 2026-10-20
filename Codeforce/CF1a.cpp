#include<bits/stdc++.h>
using namespace std;

int T;

void solve(int a, int b, int r){
    if(r == 1 || r == 4 || r == 9 || r == 16 || r == 25){
        cout << a - r << ' ' << b << endl;
        return;
    }
    else{
        switch(r){
            case 2:
                cout <<
                break;
        }
    }
    
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
	while(T --){
        int a, b, r;
        cin >> a >> b >> r;
        solve(a, b, r);
    }
	return 0;
}