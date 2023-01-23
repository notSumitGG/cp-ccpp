#include<stdio.h>
#include<math.h>

#define N 100005
#define LOG 17
int dp[N][LOG], n;

int min(int a, int b){
    if(a>b) return b;
    else    return a;
}
int query(int l, int r){
    int length = r-l+1;
    int x=log(length)/log(2);
    return min(dp[l][x], dp[r-(1<<x)+1][x]);
}
int main(){
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &dp[i][0]);

    for(int j=1; j<LOG; ++j)
        for(int i=0; j+(1<<j)-1<N; ++i)
            dp[i][j] = min(dp[i][j-1], dp[i+(i<<(j-1))][j-1]);

    int q;
    scanf(" %d", &q);
    while(q>0){
        int l, r;
        scanf(" %d %d", &l, &r);
        int m = query(l,r);
        printf(" %d\n", m);
        --q;
    }
}
