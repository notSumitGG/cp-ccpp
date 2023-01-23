#include <stdio.h>

int josephus(int n, int k){
    if(n == 1)
        return n;

    return (josephus(n - 1, k) + k) % n;
}
void main(){
    int n, k;
    printf("Enter number of players : ");
    scanf(" %d\n", &n);
    printf("Enter number of players to skip : ");
    scanf(" %d\n", &k);
    int x = josephus(n, k);
    printf("The winner is : %d", x);
}