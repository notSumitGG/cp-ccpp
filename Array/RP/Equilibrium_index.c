#include<stdio.h>

int main(){
    int x[100000], n, lsum=0, rsum=0, i;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i){
        scanf(" %d", &x[i]);
        rsum+=x[i];
    }

    for(i=0; i<n; ++i){
        rsum-=x[i];
        if(lsum==rsum)
            break;

        lsum+=x[i];
    }
    printf("Index : %d", i);
    return 0;
}
