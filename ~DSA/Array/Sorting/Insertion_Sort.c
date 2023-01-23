#include<stdio.h>

int x[100000], n;

void insertionSort(){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = x[i];
        j = i - 1;

        while (j >= 0 && x[j] > key){
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = key;
    }
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    insertionsort();
    printf("Sorted array :\n");
    for(int i = 0; i < n; i++)
        printf(" %d", x[i]);

    return 0;
}
