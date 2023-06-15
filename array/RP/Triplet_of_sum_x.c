#include<stdio.h>

void sort(int x[], int n){
    int temp, min;
    for(int i=0; i<n-1; ++i){
        min=i;
        for(int j=i+1; j<n-1; ++j)
            if(x[j] < x[min])
                min = j;

        temp = x[i];
        x[i] = x[min];
        x[min] = temp;
    }
}
int main(){
    int x[100000], n, sum;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);
    scanf(" %d", &sum);

    sort(x, n);
    int left, right;
    for(int i=0; i<n-2; ++i){
        left = i+1;
        right = n-1;
        while(left < right){
            if(x[i]+x[left]+x[right] == sum){
                printf(" %d %d %d\n", i, left, right);
                printf(" %d %d %d\n", x[i], x[left], x[right]);
                break;
            }
            else if(x[i]+x[left]+x[right] < sum)
                ++left;
            else
                --right;
        }
    }
    return 0;
}
