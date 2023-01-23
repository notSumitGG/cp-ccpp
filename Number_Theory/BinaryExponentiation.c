#include<stdio.h>

int my_fast_power(int a, int b){
    int result = 1, a0 = a;
    while(b > 0){
        if(!(b&1)){
            a *= a;
            b >>= 1;
        }
        if(b&1){
            result *= a0;
            b--;
        }
    }
    return result*a/a0;
}
int fast_power(int a, int b){
    if(b==1)    return 1;

    long res = fast_power(a, b/2);

    if(b&1)
        return a*res*res;
    else
        return res*res;
}
int fastpower(int a, int b){
    int result = 1;
    while(b){                           // or b > 0
        if(b & 1)                       // (b & 1) == (b % 2)
            result *= a;                // result = (result * (a % n)) % n

        a *= a;                         // a = ((a % n) * (a % n)) % n;
        b >>= 1;                        // (b >> 1) == (b / 2)
    }
    return result;
}
int main(){
    int x, y;
    scanf(" %d", &x);
    scanf(" %d", &y);
    printf(" %d\n", fastpower(x, y));
    return 0;
}
