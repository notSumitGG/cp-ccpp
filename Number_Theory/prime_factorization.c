#include<stdio.h>

int n, factors[1000], factcount=0;

void pfactorize(){
    int i = 2;
    int n0 = n;
    while(i <= n/2){
        while(n0%i==0){
            factors[factcount] = i;
            n0/=i;
            ++factcount;
        }
        ++i;
    }
}
int main(void){
    scanf(" %d", &n);

    pfactorize();
    for(int i=0; i<factcount; ++i)
        if(factors[i] != 0)
            printf(" %d", factors[i]);

    printf("\n");
    return 0;
}
