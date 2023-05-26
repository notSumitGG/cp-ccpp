#include<stdio.h>

int x[100000], n;

void bubblesort(){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(x[j] > x[j + 1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    bubblesort();
    printf("Sorted array :\n");
    for(int i = 0; i < n; i++)
        printf(" %d", x[i]);

    return 0;
}
