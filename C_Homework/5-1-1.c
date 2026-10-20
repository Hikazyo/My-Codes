#include <stdio.h>

int CountDigit( int number, int digit );
    
int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));
    
    return 0;
}

int CountDigit( int number, int digit ){
    int cnt = 0, n;
    if(digit == EOF)return 0;
    if(number < 0)n = -number;
    n = number;
    if(n == 0){
        if(digit == 0)return 1;
        else return 0;
    }
    while(n > 0){
        int cur = n % 10;
        if(cur == digit)cnt ++;
        n /= 10;
    }
    return cnt;
}