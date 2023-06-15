#include<stdio.h>

int x[10000], n;

int bruteforce(){
    int maxsum = 0;
    for(int i = 0; i < n; i++){
        int cursum = 0;
        for(int j = i; j < n; j++)
            cursum = cursum + i;

        if(cursum > maxsum)
            maxsum = cursum;
    }
    return maxsum;
}
int kadanesalgorithim(){
    int maxsum = x[0];
    int cursum = x[0];
    for(int i = 1; i < n; i++){
        cursum = cursum + x[i];
        if(cursum > maxsum)
            maxsum = cursum;

        if(cursum < 0)
            cursum = 0;
    }
    return maxsum;
}
int main(){
    scanf(" %d", &n);
    for(int i=0; i<n; i++)                  //include negative elements
        scanf(" %d", &x[i]);

    printf(" %d\n", kadanesalgorithim());
    return 0;
}
