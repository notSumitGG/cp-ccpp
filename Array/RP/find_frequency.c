#include<stdio.h>

int x[100000], n;

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
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);

    sort();
    if(n == 1)
        printf(" %d : %d", x[0], 1);
    else{
        int freq=1;
        for(int i=1; i<n+1; ++i)
            if(x[i] == x[i-1])
                ++freq;
            else{
                printf(" %d : %d\n", x[i-1], freq);
                freq=1;
            }
    }
    return 0;
}
