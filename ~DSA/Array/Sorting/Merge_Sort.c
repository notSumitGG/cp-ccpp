#include<stdio.h>

int x[100000], n;

void merge(int lt, int mid, int rt){
    int i, j, k, tem[100000];
    for(i=lt, j=mid+1, k = lt; i<=mid && j<=rt; ++k){
        if(x[i] < x[j]){
            tem[k] = x[i];
            ++i;
        } else {
            tem[k] = x[j];
            ++j;
        }
    }

    if(j>mid){
        while(j<=rt){
            tem[k]=x[j];
            ++k;
            ++j;
        }
    } else {
        while(i<=mid){
            tem[k]=x[i];
            ++k;
            ++i;
        }
    }

    for(k=lt; k<=rt; ++k)
        x[k]=tem[k];
}
void mergesort(int lt, int rt){
    if(lt<rt){
        int mid = (lt + rt)/2;
        mergesort(lt, mid);
        mergesort(mid+1, rt);
        merge(lt, mid, rt);
    }
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    mergesort(0, n-1);
    printf("Sorted array :\n");
    for(int i = 0; i < n; i++)
        printf(" %d", x[i]);

    return 0;
}
