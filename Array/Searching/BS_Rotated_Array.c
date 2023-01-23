#include<stdio.h>

int x[100000], n, find;

int bs_rotated(){
    int lb=0, ub=n-1, mid;

    while(lb<=ub){
        mid=(lb+ub)/2;

        if(x[mid] == find)  return mid;

        if(x[ub] < x[mid]){                                 //left sorted also x[lb] < x[mid]
            if(find >= x[lb] && find < x[mid])
                ub = mid-1;
            else                                            //if(find > x[mid] && find < x[ub])
                lb = mid+1;
        }
        else if(x[mid] < x[lb]){                            //right sorted also x[mid] < x[ub]
            if(find > x[mid] && find <= x[ub])
                lb = mid+1;
            else                                            //if(find < x[mid] && find > x[lb])
                ub = mid-1;
        }
    }
    return -1;
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %d", &x[i]);

    scanf(" %d", &find);

    int result = bs_rotated();
    if(result != -1)
        printf("Index of %d : %d\n", find, result);
    else
        printf("Index of %d is not found\n", find);

    return 0;
}
