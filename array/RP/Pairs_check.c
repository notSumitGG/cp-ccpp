#include<stdio.h>
#include<stdbool.h>

int x[10000], n, sum;

bool printPairs(){
    int i, rem[10000];

    for(i = 0; i < n; ++i)          //this only works for positive integers
        if(x[i] < sum)
            ++rem[x[i]];

    int mid = (sum-1)/2;
    for(i = 1; i<=mid; ++i)
        if(rem[i] > 0 && rem[sum-i] > 0)
            return true;

    if(sum%2==0 && rem[mid+1] > 1)
        return true;
    
    return false;
}
int main(){
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);
    scanf(" %d", &sum);

    if(printPairs()==true)
        printf("There is atleast a pair\n");
    else
        printf("There is not a single pair\n");

    return 0;
}
