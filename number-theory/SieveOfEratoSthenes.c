#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPrime[10000];

void sieveoferatosthenes(int n){
    memset(isPrime, true, sizeof(isPrime));

    for(int i = 2; i * i <= n; i++)
        if(isPrime[i] == true)
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
}
int main(){
    int n;
    scanf(" %d", &n);
    sieveoferatosthenes(n);

    for(int i = 2; i <= n; i++)
        if(isPrime[i])
            printf(" %d",i);

    return 0;
}
