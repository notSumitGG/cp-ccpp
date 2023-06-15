#include<stdio.h>
// Given array of N integers. Given Q quesies and in each query given L and R
// print sum of array elements from index L to R (l, R included)
// Constraints
// 1 <= N <= 10^5
// 1 <= a[i] <= 10^9
// 1 <= Q <= 10^5
// 1 <= L, R <= N
long long int a[1000000];

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);

    int l, r, k;
    while(q--) {
        scanf(" %d %d %d", &l, &r, &k);
        a[l]+=k;
        a[r+1]-=k;
    }
    //finding max
    long long int max = ~(1<<31 - 1);
    for(int i=1; i<=n; ++i) {
        a[i]+=a[i-1];
        if(max < a[i])
            max = a[i];
    }
    printf(" %d\n", max);
    return 0;
}
