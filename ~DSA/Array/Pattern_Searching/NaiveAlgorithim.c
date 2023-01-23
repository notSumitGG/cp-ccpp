#include <stdio.h>
#include <string.h>
#define l 10000

int BruteForce(char s[], char p[]){       //s is bigger string and p is smaller string
    int j, k, ls, lp;
    ls = strlen(s);
    lp = strlen(p);
    for(int i = 0; i <= ls - lp; i++){
        j = i;
        k = 0;
        while(s[j] == p[k] && k < lp){
            j++;
            k++;
        }
        if(k == lp)
            return i;
    }
    return -1;
}
