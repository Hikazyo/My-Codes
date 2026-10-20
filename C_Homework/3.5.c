#include<stdio.h>
#include<math.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == 0.0 && b == 0.0 && c == 0.0)printf("Zero Equation");
    if(a == 0.0 && b == 0.0)printf("Not An Equation");
    double delta = b * b - 4 * a * c;
    if(delta > 0.0){
        double ans1 = (-b + sqrt(delta)) / (2 * a), ans2 = (-b - sqrt(delta)) / (2 * a);
        printf("%.2lf\n%.2lf", ans1, ans2);
    }
    else if(delta == 0.0){
        double ans = -b / 2 * a;
        printf("%.2lf", ans);
    }
    else{
        double cur = (-b) / 2 * a, ans1 = delta / 2 * a;
        printf("%.2lf + %.2lfi\n%.2lf - %.2lfi", cur, ans1, cur, ans1);
    }
    return 0;
}