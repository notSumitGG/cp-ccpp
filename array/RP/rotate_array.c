#include<stdio.h>
#include<stdlib.h>

void clockwise(int x[], int n, int k){
    int *temp = (int *)malloc(sizeof(int)*k);

    for(int i=0; i<k; ++i)
        temp[i] = x[i];

    for(int i=0; i<n-k; ++i)
        x[i] = x[i+k];

    for(int i=n-k; i<n; ++i)
        x[i] = temp[i-(n-k)];

    for(int i=0; i<n; ++i)
        printf(" %d", x[i]);
    printf("\n");
}
void anticlockwise(int x[], int n, int k){
    int *temp = (int *)malloc(sizeof(int)*k);

    for(int i=n-k; i<n; ++i)
        temp[i-(n-k)] = x[i];

    for(int i=n-k-1; i>=0; --i)
        x[i+k] = x[i];

    for(int i=0; i<k; ++i)
        x[i] = temp[i];

    for(int i=0; i<n; ++i)
        printf(" %d", x[i]);
    printf("\n");
}
int main(){
    int x[1000], n, k;          // 1<=k
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);
    scanf(" %d", &k);

    // int x[] = {0,1,2,3,4,5,6,7,8};
    // int k=4, n=9;

    //anticlockwise(x, n, k);
    clockwise(x, n, k);
    return 0;
}
