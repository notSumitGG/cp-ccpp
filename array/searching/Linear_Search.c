#include<stdio.h>

int linear_search(int x[], int n, int find){
    int i;
    for(i = 0; i < n; i++){
        if(find == x[i])
        return i;
    }
    return -1;
}
int main(){
    int x[10000], n, find;

    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    scanf(" %d", &find);

    int index = linear_search(x, n, find);
    if(index != -1)
        printf("%d at index %d\n", find, index);
    else
        printf("%d not found\n", find);

    return 0;
}
