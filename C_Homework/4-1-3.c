#include<stdio.h>

int main(){
    double dis, h;
    int n;
    scanf("%lf %d", &h, &n);

    if(n == 0){
        printf("0.0 0.0");
        return 0;
    }

    dis = h;
    double turn = h / 2;
    for(int i = 2;i <= n;i ++){
        dis += 2 * turn;
        turn /= 2;
    }

    printf("%.1lf %.1lf", dis, turn);
    return 0;
}