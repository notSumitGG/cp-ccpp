#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void sieveoferatosthenes(bool isPrime[], int n){
    for(int i=2; i<n; ++i)
        isPrime[i] = true;

    for(int i = 2; i * i <= n; i++)
        if(isPrime[i] == true)
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
}
int main(){
    int n;
    scanf(" %d", &n);
    bool *isPrime = (bool *)malloc(sizeof(int)*n);
    sieveoferatosthenes(isPrime, n);

    int i=2, j=n-1;
    while(i <= j){
        if(i + j < n){
            ++i;
            while(!isPrime[i]) ++i;
        }
        else if(i + j > n){
            --j;
            while(!isPrime[j]) --j;
        }
        else{
            if(isPrime[i] && isPrime[j]){
                printf(" %d + %d = %d\n", i, j, n);
                --j;// ++i;
            }
        }
    }
    if(isPrime[i] && isPrime[j])
        printf("Not possible\n");
    return 0;
}
