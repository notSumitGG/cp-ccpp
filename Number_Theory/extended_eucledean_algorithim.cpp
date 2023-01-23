#include<stdio.h>

int gcd_extended(int a, int b, int *x, int *y){
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcd_extended(b, a % b, &x1, &y1);
    //printf(" %d %d %d %d\n", x1, y1, *x, *y);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return gcd;
}
int main(){
    int a, b, x, y;
    scanf(" %d", &a);
    scanf(" %d", &b);

    int res = gcd_extended(a, b, &x, &y);
    printf(" %d(%d) + %d(%d) = %d\n", a, x, b, y, res);
    return 0;
}
