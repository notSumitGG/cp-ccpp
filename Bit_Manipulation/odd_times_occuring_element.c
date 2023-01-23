//Given an array of integers. All numbers occur even no of times except one number which occurs odd number of times.
#include<stdio.h>

int main(){
    int x[10000], n;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);

    int result = x[0];
    for(int i=1; i<n; ++i)
        result^=x[i];

    printf("Once occuring element : %d", result);
    return 0;
}
