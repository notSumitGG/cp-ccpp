#include<stdio.h>

int x[100000];

// by Luv
int binary_search(int left, int right, int find){
    int mid;
    while(right - left > 1) {
        mid = left + (right - left) / 2;
        if(x[mid] < find) 
            left = mid + 1;
        else
            right = mid;
    }
    if(x[right] == find) return right;
    else if(x[left] == find) return left;
    else return -1;
}

int binarysearch(int left, int right, int find){
    int mid;
    while(left <= right){
        mid = left + (right-left)/2;

        if(x[mid] < find)
            left = mid + 1;
        else if(x[mid] > find)
            right = mid - 1;
        else if(x[mid] == find)
            return mid;
    }
    return -1;
}

int main(void){
    int n, find;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    scanf(" %d", &find);

    int result = binarysearch(0, n-1, find);
    if(result != -1)
        printf("Index of %d : %d\n", find, result);
    else
        printf("Index of %d is not found\n", find);

    return 0;
}
