#include<stdio.h>

int x[10000], n, k;

void sort(){
    int temp, min;
    for(int i=0; i<n-1; ++i){
        min = i;
        for(int j=i+1; j<n; ++j)
            if(x[j]<x[min])
                min = j;

        temp = x[min];
        x[min] = x[i];
        x[i] = temp;
    }
}
int main(){
    scanf(" %d", &n);
    for(int i=0; i<n; i++)
        scanf(" %d", &x[i]);

    scanf(" %d", &k);

    sort();
    printf("%dth largest %d", k, x[n-k]);
    return 0;
}
