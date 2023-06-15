#include<stdio.h>

int x[100000], n;

void swap(int a, int b){
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}
int partition(int low, int high){
    int pivot = x[low];
    int i = low;
    int j = high;
    while(i < j){
        while(x[i]<=pivot)  ++i;
        while(x[j]>pivot)   --j;
        if(i<j)
            swap(i, j);
    }
    swap(j, low);
    return j;
}
void quicksort(int low, int high){
    if(low < high) {
        int pivotindex = partition(low, high);
        quicksort(low, pivotindex-1);
        quicksort(pivotindex+1, high);
    }
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    quicksort(0, n-1);
    printf("Sorted array :\n");
    for(int i = 0; i < n; i++)
        printf(" %d", x[i]);

    return 0;
}
