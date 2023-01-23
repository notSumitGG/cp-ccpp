#include<stdio.h>

int jump[10000];

int main(){
    int n;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &jump[i]);

    int i=0, jumps = 0;
    while(i < n){
        int max = i;
        for(int j=i+1; j<=i+i; ++j)
            if(max < jump[j])
                max = j;

        i += jump[max];
        ++jumps;
    }
    printf(" %d\n", jumps);
    return 0;
}
