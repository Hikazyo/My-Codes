#include<stdio.h>

int max(int a, int b){return (a > b) ? a : b;}
int main(){ 
    int n;
    scanf("%d", &n);
    int g[n + 1][n + 1], sum[n + 1];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            scanf("%d", &g[i][j]);
    sum[0] = 0;
    for(int i = 1;i <= n;i ++){
        sum[i] = sum[i - 1] + g[i][i];
    }
    int ans = -0x3f3f3f3f;
    for(int i = 1;i <= n;i ++){
        int cur = max(sum[i], sum[i] + g[i][i]);
        ans = max(ans, cur);
    }
    printf("%d", ans);

    return 0;
}