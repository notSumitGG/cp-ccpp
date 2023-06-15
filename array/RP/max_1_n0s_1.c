#include<stdio.h>

char bin[10000];
int n;

int max0s(){
    int left=0, right=0, minleft=0, maxright=0;
    for(int i=0; i<n; ++i){
        if(bin[i] == 49){
            left = right;
            right = i;
        }
        if((maxright-minleft) < (right-left)){
            minleft = left;
            maxright = right;
        }
    }
    return maxright - minleft - 1;
}
int main(){
    scanf(" %s", bin);
    n = strlen(bin);

    int m = max0s();
    printf("Max Difference : %d\n", m);
    return 0;
}
