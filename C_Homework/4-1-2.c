#include<stdio.h>

int a[10001];
int fib(int n){
    a[1] = 1, a[2] = 1;
    for(int i = 3;i <= n;i ++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("0");
        return 0;
    }
    int i = 1;
    while(fib(i) < n)i ++;
    printf("%d", i);


    return 0;
}
// 1 1 2 3 5 8 13 21 
// 1 2 4 7 12 20 33