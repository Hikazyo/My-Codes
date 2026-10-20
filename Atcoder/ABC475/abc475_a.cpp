#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    int l = a.length();
    for(int i = 0;i < l;i ++){
        if(i == l - 1){
            cout << a[i];
            return 0;
        }
        cout << a[i] << 'o';
    }


    return 0;
}