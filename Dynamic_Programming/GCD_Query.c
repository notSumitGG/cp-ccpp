#include<stdio.h>
// https://www.codechef.com/problems/GCDQ
// You are given an array A of integers of size N. You will be given Q queries
// where each query is represented by two integers L, R. You have to find the
// gcd(Greatest Common Divisor) of the array after excluding the part from range
// L to R inclusive (1 Based indexing). You are guaranteed that after excluding
// the part of the array remaining array is non empty.
int gcd(int a, int b) {
    if(b==0)
        return a;
    else
        gcd(b, a%b);
}
int main() {
    int num[10000], n;
    int fd[10000], bk[10000];
    scanf(" %d", &n);
    fd[0] = 0;
    bk[n+1] = 0;
    for(int i=1; i<=n; ++i) {
        scanf(" %d", &num[i]);
        fd[i] = gcd(fd[i-1], num[i]);
    }
    for(int i=n; i>=1; --i){
        bk[i] = gcd(bk[i+1], num[i]);
    }
    int q, l, r;
    scanf(" %d", &q);
    while(q--) {
        scanf(" %d %d", &l, &r);
        int res = gcd(fd[l-1], bk[r+1]);
        printf(" %d\n", res);
    }
    return 0;
}
