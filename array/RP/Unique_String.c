#include<stdio.h>
#include<string.h>

char s[100000];
int n;
int hash[128];

int main(){
    scanf(" %s", s);
    n=strlen(s);
    //memset(hash, 0, 128*4);

    for(int i=0; i<n; ++i)
        hash[s[i]]++;

    for(int i=0; i<128; ++i)
        if(hash[i]>0)
            printf("%c", i);

    printf("\n");
    return 0;
}
