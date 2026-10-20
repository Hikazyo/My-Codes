#include<stdio.h>

int main(){
    int n, ans;
    scanf("%d %d", &ans, &n);
    int cnt = 1;
    while(n --){
        int x;
        scanf("%d", &x);
        if(x < 0){
            printf("Game Over");
            return 0;
        }
        if(x < ans){
            printf("Too small\n");       
        }
        else if(x == ans){
            if(cnt <= 3 && cnt != 1) printf("Lucky You!");
            else if(cnt > 3) printf("Good Guess!");
            else printf("Bingo!");
            return 0;
        }
        else{
            printf("Too big\n");
        }
        cnt ++;

    }
    printf("Game Over");
    return 0;
}