#include<stdio.h>
//day4 q2
//Find the maximum difference between two array elements of an array such that larger element appears after the smaller number
int main(){
    int x[100], n, i;

    scanf(" %d", &n);
    for(i=0; i<n; ++i)
        scanf(" %d", &x[i]);

    int min=x[0], maxdiff=0;

    for(i=1; i<n; ++i){
        if(x[i]<=min)
            min=x[i];
        if(x[i]-min>maxdiff)
            maxdiff=x[i]-min;
    }
    printf(" %d", maxdiff);
    return 0;
}
