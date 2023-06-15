#include<stdio.h>
#include<vector>
#include<string.h>
#include<limits.h>
using namespace std;

#define ll long long
vector<int> coin;
int dp[10010];

ll cc(ll amt) {
    if(amt == 0) return 0;
    if(dp[amt] != -1) return dp[amt];

    ll ans = INT_MAX;
    for(ll c: coin) {
        if(amt - c >= 0)
            ans = min(ans, cc(amt - c) + 1);
    }
    return dp[amt] = ans;
}

int coinChange(vector<int>& coin, int amt) {
    memset(dp, -1, sizeof(dp));
    int ans = cc(amt);
    return (ans == INT_MAX ? -1 : ans);
}

int main() {
    int n, amt;
    scanf("%d %d ", &n, &amt);
    coin = vector<int> (n);
    for(int i=0; i<n; ++i) 
        scanf(" %d", &coin[i]);
    
    int res = coinChange(coin, amt);
    printf("%d\n", res);

    for(int i=0; i<n; ++i)
        printf(" %d", dp[i]);
    return 0;
}