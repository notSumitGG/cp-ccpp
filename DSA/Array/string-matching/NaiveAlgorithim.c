#include <stdio.h>
#include <string.h>
#define l 10000

int bruteForce(char s[], char p[]) {
    int j, k, lens, lenp;
    lens = strlen(s);       // s is bigger string
    lenp = strlen(p);       // p is smaller string
    for(int i = 0; i <= lens - lenp; i++) {
        k = 0;
        while(s[i+k] == p[k] && k < lenp)
            k++;
        
        if(k == lenp)
            return i;
    }
    return -1;
}
