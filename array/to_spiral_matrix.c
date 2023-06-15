#include<stdio.h>
#include<math.h>
#include<string.h>

void extra_varbs(char x[], char spiral[100][100], int s){
    int r=0, e=-1, index = 0;
    while(s>0){

        for(int i=1;i<=s;i++)
            spiral[r][++e] = x[index++];

        for(int i=1;i<s;i++)
            spiral[++r][e] = x[index++];

        for(int i=1;i<s;i++)
            spiral[r][--e] = x[index++];

        for(int i=1;i<s-1;i++)
            spiral[--r][e] = x[index++];

        s-=2;
    }
}
void no_extra_varbs(char x[], char spiral[100][100], int s){
    int index = 0, cx = s-1;
    for(int i=0; i<(s+1)/2; ++i){

        for(int j=i; j<cx; ++j)
            spiral[i][j] = x[index++];

        for(int j=i; j<cx; ++j)
            spiral[j][s-i-1] = x[index++];

        for(int j=cx; j>i; --j)
            spiral[s-i-1][j] = x[index++];

        for(int j=cx; j>i; --j)
            spiral[j][i] = x[index++];

        --cx;
    }
}
int main(){
    char x[10000], spiral[100][100];
    scanf(" %s", x);
    int n = strlen(x);
    int s = ceil(sqrt(n));

    // n = 19;
    // x[0] = 1;
    // x[1] = 2;
    // x[2] = 3;
    // x[3] = 4;
    // x[4] = 5;
    // x[5] = 6;
    // x[6] = 7;
    // x[7] = 8;
    // x[8] = 9;
    // x[9] = 10;
    // x[10] = 11;
    // x[11] = 12;
    // x[12] = 13;
    // x[13] = 14;
    // x[14] = 15;
    // x[15] = 16;
    // x[16] = 17;
    // x[17] = 18;
    // x[18] = 19;

    no_extra_varbs(x, spiral, s);

    for(int i=0; i<s; ++i){
        for(int j=0; j<s; ++j)
            printf(" %c\t", spiral[i][j]);

        printf("\n");
    }
    return 0;
}
