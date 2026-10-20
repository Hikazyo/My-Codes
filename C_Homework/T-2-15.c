#include<stdio.h>

int main(){
    int L, N;
    scanf("%d %d", &L, &N);

    int bi[10], cnt = 1, num = N - 1;
    while(N > 0){
        bi[cnt] = 25 - num % 26;
        num /= 26;
        cnt ++;
    }
    for(int i = cnt - 1;i > 0;i --)
        printf("%c", bi[i] + 'a');
    

    return 0;
}