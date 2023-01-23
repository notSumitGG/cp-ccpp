#include<stdio.h>

int main(){
    int nth, sum;
    scanf(" %d", &nth);         //nth whole number
    scanf(" %d", &sum);         //numbers having sum sum

    int c=0;                    //c->nth counter
    int nsum=0;                 //nsum->sum checker
    int n=1;
    printf(" Integer Sum \t nth\n");
    while(nth != c){
        if(n%10 == 0)       nsum-=8;
        else                ++nsum;

        if(nsum == sum)     ++c;

        printf(" %d\t %d\t %d\n", n, nsum, c);
        ++n;
    }
}
