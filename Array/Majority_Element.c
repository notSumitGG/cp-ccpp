#include<stdio.h>

int x[10000], n;

int bruteforce(){
    int answerindex = 0;
    int indexcount = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(i == j)
                count++;
        }
        if(indexcount < count){
            answerindex = i;
            indexcount = count;
        }
    }
    return answerindex;
}
int boyermoore(){
    int answerindex = 0;
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(x[i] == x[answerindex])  count++;
        else                        count--;

        if(count == 0){
            answerindex = i;
            count = 1;
        }
    }
    return answerindex;
}
int main(){
    scanf(" %d", &n);
    for(int i=0; i<n; i++)
        scanf(" %d", &x[i]);

    printf("Majority Element : %d\n", x[boyermoore()]);
    return 0;
}
