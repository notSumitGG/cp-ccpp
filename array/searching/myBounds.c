#include<stdio.h>

int lower_bound(int x[], int low, int high, int find){
    int res = high+1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(find <= x[mid]){
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if(x[res] == find)
        return res;
    else 
        return -1;
}
int upper_bound(int x[], int low, int high, int find){
    int res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(x[mid] <= find){
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if(x[res] == find)
        return res;
    else 
        return -1;
}
int main(){
    int x[10000], n;
    int low, high, find;

    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);
    scanf(" %d %d %d", &low, &high, &find);

    int lb = lower_bound(x, low, high, find);
    int ub = upper_bound(x, low, high, find);
    printf(" %d %d \n", lb, ub);
    return 0;
}
/*13
0 1 2 3 4 5 5 5 8 9 10 11 12
0 12 5*/
/*1
1
0 0 1*/
