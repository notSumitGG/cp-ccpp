#include<stdio.h>

int compute_gcd(int a, int b){
    if(b==0)
        return a;

    compute_gcd(b, a%b);
}
int compute_lcm(int a, int b){
    return (a*b)/compute_gcd(a,b);
}
int main(){
    int x[1000], n;
    scanf(" %d", &n);
    scanf(" %d", &x[0]);

    long lcm=x[0], gcd=x[0];
    for(int i=1; i<n; ++i){
        scanf(" %d", &x[i]);
        gcd = compute_gcd(gcd, x[i]);
        lcm = compute_lcm(lcm, x[i]);
    }

    printf("GCD: %d\n", gcd);
    printf("LCM: %d\n", lcm);
    return 0;
}
