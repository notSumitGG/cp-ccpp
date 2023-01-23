#include<stdio.h>
//mising integer between 1 and n
int num[10000], n;
int hash[10001];

int main(void){
    scanf(" %d", &n);
    for(int i=1; i<n; ++i){
        scanf(" %d", &num[i]);
        ++hash[num[i]];
    }
    for(int i=1; i<=n; ++i)
        if(hash[i] == 0){
            printf("Integer : %d", i);
            break;
        }
    return 0;
}
