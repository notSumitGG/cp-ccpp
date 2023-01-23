#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//day3 q2
//display prime numbers between two intervals

int isprime[100];

int main(){
    int n1, n2, i, j;
    scanf(" %d", &n1);
    scanf(" %d", &n2);
    memset(isprime, true, sizeof(isprime));

    for(i=1; i*i <= n2; ++i)                //using sieve of eratostenes
        if(isprime[i]==true)
            for(j=i*i; j<=n2; j+=i)
                isprime[j]=false;

    for(i=n1; i<=n2; ++i)           //for display
        if(isprime[i]==true)
            printf(" %d", i);

    return 0;
}
