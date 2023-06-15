#include<stdio.h>
#include<vector>
#include<cmath>
#include<string.h>
#include<limits.h>
using namespace std;

const int N = 25e2+10;
vector<int> a(N);
int dp[N];

// the increasing subsequence may not be contiguous
int lis(int n) {
    if(dp[n] != -1) return dp[n];
    int ans = 1;
    for(int i=0; i<n; ++i) {
        if(a[n] > a[i]) {
            ans = max(ans, lis(i) + 1);
        }
    }
    return dp[n] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) 
        scanf("%d", &a[i]);
    
    int res = INT_MIN;
    for(int i=0; i<n; ++i) 
        res = max(res, lis(i));

    printf("%d\n", res);
    return 0;
}

/*
8
10 9 2 5 3 7 101 18
*/
