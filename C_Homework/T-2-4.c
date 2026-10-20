#include<stdio.h>

int sum(int n){
    int ans = 0;
    while(n > 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i ++){
        int x;
        scanf("%d", &x);
        int bl = sum(x);
        int check = 1;
        for(int i = 2;i <= 9;i ++){
            int cur = sum(x * i);
            if(cur != bl)check = 0;
        }
        if(check)printf("%d\n", bl);
        else printf("NO\n");
    }

    
    return 0;
}