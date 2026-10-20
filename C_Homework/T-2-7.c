#include<stdio.h>

int main(){
    int a[110];
    int n;
    scanf("%d", &n);
    int l = 1, now = n;
    while(now > 0){
        now -= 1 << l;
        l ++;
    }
    //printf("%d\n", l);
    for(int i = l - 1;i > 0;i --){
        int x = n % 2;
        if(x == 0)printf("4\n");
        else printf("7\n");
        n /= 2;
    }

    return 0;
}