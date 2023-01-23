#include<stdio.h>
#define n 10

int min(int a, int b){
    if(a > b)
        return b;
    else
        return a;
}
int auxarray(int *x){
    int maxleft[n], maxright[n], water = 0;
    maxleft[0] = x[0];
    for(int i = 1; i < n; i++)
        if(maxleft[i - 1] < x[i])
            maxleft[i] = x[i];

    maxright[n - 1] = x[n - 1];
    for(int i = n - 2; i >= 0; i--)
        if(maxright[i + 1] < x[i])
            maxright[i] = x[i];

    for(int i = 0; i < n; i++)
        water += min(maxleft[i], maxright[i]) - x[i];

    return water;
}
int watercount(int *x){
    int max = x[0], index = 0, water = 0, tsw = 0;
    for(int i = 1; i < n; i++){
        if(max <= x[i]){
            max = x[i];
            index = i;
        }
        else if(max > x[i] && x[i] > x[i + 1])
            tsw += (min(max, x[i + 1]) - x[i]) * (i - index);

        else if(max > x[i] && x[i] < x[i + 1]){
            water += (min(max, x[i + 1]) - x[i]) * (i - index) + tsw;
            tsw = 0;
        }
    }
    return water;
}
int main(){
    int x[n + 1];
    x[n] = 0;
    printf("Enter elements in the arrray : \n");
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    printf("Rainwater Trapped : %d", watercount(x));
    return 0;
}
