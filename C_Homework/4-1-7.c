#include<stdio.h>

int getgit(int n){
    int sum = n / 10000 % 10 + n / 1000 % 10 + n / 100 % 10 + n / 10 % 10 + n % 10;
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);

    int cnt = 1, latest = n;
    while(1){
        int cur = getgit(latest) * 3 + 1;
        printf("%d:%d\n", cnt, cur);
        if(cur == latest){
            break;
        }
        latest = cur;
        cnt ++;
    }

    return 0;
}