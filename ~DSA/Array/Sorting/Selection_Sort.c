#include<stdio.h>

int x[100000], n;

void selectionsort(int x[], int n){
    int min, temp;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++)
            if(x[j] < x[min])
                min = j;

        temp = x[min];
        x[min] = x[i];
        x[i] = temp;
    }
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    selectionsort();
    printf("Sorted array :\n");
    for(int i = 0; i < n; i++)
        printf(" %d", x[i]);

    return 0;
}
