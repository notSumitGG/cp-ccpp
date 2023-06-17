#include <stdio.h>

int countpaths(int m, int n){
    if(m == 1 || n == 1)
        return 1;
    else
        return countpaths(m - 1, n) + countpaths(m, n - 1);
}
void main(){
    int m, n;
    scanf(" %d %d\n", &m, &n);
    int x = countpaths(m, n);
    printf("The winner is : %d", x);
}
