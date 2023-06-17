#include<stdio.h>

void printmove(int a, int b){
    printf("%d->%d\n", a, b);
}
void hanoi(int n, int start, int end){
    if(n == 1)
        printmove(start, end);
    else {
        int other = 6 - (start + end);
        hanoi(n - 1, start, other);
        printmove(start, end);
        hanoi(n - 1, other, end);
    }
}
int main(){
    int n, start, end;
    printf("Enter nummber of discs :");
    scanf(" %d", &n);
    printf("Enter starting stack :");
    scanf(" %d", &start);
    printf("Enter ending atack :");
    scanf(" %d", &end);

    if(start != end && n > 0 && start >= 1 && start <= 3 && end >= 1 && end <= 3)
        hanoi(n, start, end);
    else
        printf("Enter correctly");
        
}