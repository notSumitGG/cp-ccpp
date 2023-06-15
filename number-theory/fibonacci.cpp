#include<stdio.h>
#include<string.h>

int dp[10000], n;

int recursion(int n){
    if(n==0)  return 0;
    if(n==1)  return 1;

    return recursion(n-1) + recursion(n-2);
}
int dynamic_programming(int n){
    if(n==0)  return 0;
    if(n==1)  return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = dynamic_programming(n-1) + dynamic_programming(n-2);
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf(" %d", &n);
    printf(" %d\n", dynamic_programming(n));
    return 0;
}
