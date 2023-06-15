#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<cmath>
const int N = 100000;
// https://atcoder.jp/contests/dp/tasks/dp_b
int stone[N];
int dp[N];
int k;

int bruteforce(int n) { // TOP_DOWN
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int cost = INT_MAX;
    for(int i=1; i<=k; ++i) {
        if(n-i >= 0)
            cost = std::min(cost, bruteforce(n-i) + abs(stone[n-i] - stone[n]));
    }

    return dp[n] = cost;
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) 
        scanf("%d", &stone[i]);

    memset(dp, -1, sizeof(int)*n);
    printf("%d\n", bruteforce(n-1));
    return 0;
}