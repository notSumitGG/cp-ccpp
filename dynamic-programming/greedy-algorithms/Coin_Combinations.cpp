#include<stdio.h>
#include<vector>
#include<string.h>
#include<limits.h>
using namespace std;

vector<int> coin;
int dp[310][10010];
int comb = 0;

int cc(int index, int amt) {
    if(amt == 0) return 1;
    if(index < 0) return 0;
    if(dp[index][amt] != -1) return dp[index][amt];

    int ways = 0;
    for(int camt=0; camt <= amt; camt+=coin[index]) {
        ways += cc(index-1, amt-camt);
    }
    return dp[index][amt] = ways;
}

int change(vector<int>& coin, int amt) {
    memset(dp, -1, sizeof(dp));
    return cc(coin.size()-1, amt);
}

int main() {
    int n, amt;
    scanf("%d %d", &n, &amt);
    coin = vector<int> (n);
    for(int i=0; i<n; ++i) 
        scanf(" %d", &coin[i]);
    
    int res = change(coin, amt);
    printf("%d\n", res);
}