#include<stdio.h>

void iteration(int x[], int n, int s){
    for(int mask=0; mask<(1<<n); ++mask){
        long sum_of_subset = 0;
        for(int i=0; i<n; ++i){
            if(mask & (1<<i))
                sum_of_subset+=x[i];
        }
        for(int j=n-1; j>=0 && sum_of_subset == s; --j){
            if(mask && (1<<j))
                printf(" %d", x[j]);
            if(j==0)
                printf("\n");
        }
    }
}
void backtracking(int *x, int sum, int i, int s){
    if(sum==s)
        printf(" yes ");
    if(sum<s)
        backtracking(x, sum+x[i], i+1, s);

    backtracking(x, sum, i+1, s);
}
int main(){
    int x[100], n, s;

    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);
    scanf(" %d", &s);         //s is target sum

    backtracking(x, 0, 0, s);
    return 0;
}
