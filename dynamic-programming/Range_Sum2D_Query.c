#include<stdio.h>

const int d = 100;
int x[d][d], dp[d][d], n;

int main() {
    scanf(" %d", &n);
    dp[0][0] = 0;
    for(int i=1; i<=n; ++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
        for(int j=1; j<=n; ++j){
            scanf(" %d", x[i][j]);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + x[i][j];
        }
    }

    int q, row_up, row_down, col_left, col_right;
    scanf(" %d", &q);
    while(q--) {
        scanf(" %d %d %d %d", &row_up, &col_left, &row_down, &col_right);
        printf(" %d", dp[row_down][col_right] - dp[row_up-1][col_right] - dp[row_down][col_left-1] + dp[row_up-1][col_left-1]);
    }
    return 0;
}
