#include<stdio.h>

int binary_search(int x[], int lb, int ub, int find){
    if(lb > ub)
        return -1;

    int mid=(lb+ub)/2;
    if(x[mid] < find)
        binary_search(x, mid + 1, ub, find);
    else if(x[mid] > find)
        binary_search(x, lb, mid - 1, find);
    else
        return mid;
}
int main(){
    int x[10000], n, find;

    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);

    scanf(" %d", &find);

    int index = binary_search(x, 0, n - 1, find);
    printf(" %d", index);
    return 0;
}
