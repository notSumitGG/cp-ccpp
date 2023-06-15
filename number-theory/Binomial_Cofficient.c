#include<stdio.h>

long iteration(int n, int r){
    double c=1.0;

    if(r > n-r)
        r = n-r;

    for(int i=0; i<r; ++i){
        c*=(n-i);
        c/=(i+1);
    }
    return c;
}
long recursion(int n, int k){
    if(k>n)
        return 0;
    if(k==0 || k==n)
        return 1;

    return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}
int main(){
    int n, r;
    scanf(" %d", &n);
    scanf(" %d", &r);
    printf(" %ld\n", iteration(n, r));
    return 0;
}
