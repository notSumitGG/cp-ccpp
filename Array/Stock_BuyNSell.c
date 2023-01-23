#include<stdio.h>
#include<math.h>

int max(int a, int b){
    return (a>b ? a:b);
}
int min(int a, int b){
    return (a<b ? a:b);
}
int bruteforce(int *x, int n){
    int maxprofit = 0;
    int curprofit = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            curprofit = x[j] - x[i];
            if(curprofit > maxprofit)
                maxprofit = curprofit;
        }
    }
    return maxprofit;
}
int auxarray_pastmin(int *x, int n){
    int aux[n], maxprofit = 0;
    aux[0] = x[0];

    for(int i = 1; i < n; i++)
        aux[i] = min(x[i], aux[i - 1]);

    for(int i = 0; i < n; i++){
        int curprofit = x[i] - aux[i];
        if(curprofit > maxprofit)
            maxprofit = curprofit;
    }
    return maxprofit;
}
int auxarray_futuremax(int *x, int n){
    int aux[n], maxprofit = 0;
    aux[n - 1] = x[n - 1];

    for(int i = n - 2; i >= 0; i--)
        aux[i] = max(x[i], aux[i + 1]);

    for(int i = 0; i < n; i++){
        int curprofit = aux[i] - x[i];
        if(curprofit > maxprofit)
            maxprofit = curprofit;
    }
    return maxprofit;
}
int mostoptimized(int *x, int n){
    int minSoFar = x[0], maxprofit = 0;

    for(int i = 1; i < n; i++){
        minSoFar = min(minSoFar, x[i]);
        int curprofit = x[i] - minSoFar;
        maxprofit = max(curprofit, maxprofit);
    }
    return maxprofit;
}
int main(){
    int x[10000], n;
    scanf(" %d", &n);
    for(int i=0; i<n; i++)
        scanf(" %d", &x[i]);

    printf("Maximum profit : %d", mostoptimized(x, n));
    return 0;
}
