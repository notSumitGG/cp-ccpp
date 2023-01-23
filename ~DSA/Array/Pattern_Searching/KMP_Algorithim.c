#include<stdio.h>
#include<string.h>

void computeLPSArray(char *p, int m, int *lps){
    int i = 1, j = 0;
    lps[0] = 0;
    // length of the previous longest prefix suffix
    while(i < m){
        if(p[i]==p[j])
            lps[i++] = ++j;
        else{
            if(j!=0)
                j=lps[j-1];
            else
                lps[i++] = 0;
        }
    }
    /*lps[0]=-1;
    for(i=1; i<m; ++i){
        j=aux[i-1];

        while((p[i]!=p[j+1]) && (j>=0))
            k=lps[j];

        if(p[i]==p[kj+1])
            lps[i]=j+1;
        else
            lps[i]-1;
    }*/
}
void knuth_morris_pratt(char s[], char p[]){
    int i = 0, j = 0;
    int lps[10000], n = strlen(s), m = strlen(p);
    computeLPSArray(p, m, lps);

    while(i<n){                     //pattern searching
        if(s[i]==p[j]){
            ++i;
            ++j;
        }
        else{
            if(j != 0)
                j = lps[j-1];
            else
                ++i;
        }

        if(j == m){
            printf("%d\n", i - j);
            j = lps[j - 1];
        }
    }
}
