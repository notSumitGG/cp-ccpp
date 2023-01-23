#include<stdio.h>

int main() {
    int x[10000], dp[10000], n;
    scanf(" %d", &n);
    dp[0] = 0;
    for(int i=1; i<=n; ++i) {
        scanf(" %d", x[i]);
        dp[i] = dp[i-1] + x[i];
    }

    int q, l, r;
    scanf(" %d", &q);
    while(q--) {
        scanf(" %d %d", &l, &r);
        printf(" %d", dp[r] - dp[l-1]);
    }
    return 0;
}
