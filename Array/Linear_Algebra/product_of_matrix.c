#include<stdio.h>

int x[1000][1000], y[1000][1000], product[1000][1000];
int r1, c1, r2, c2;

void input(int x[1000][1000], int n, int m){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            scanf(" %d", &x[i][j]);
    }
}
void computeproduct(int x[1000][1000], int y[1000][1000], int product[1000][1000]){
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            product[i][j] = 0;
            for(int k = 0; k < c1; k++)
                product[i][j] += x[i][k] * y[k][j];
        }
    }
}
void display(int x[1000][1000], int n, int m){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            printf(" %d", x[i][j]);
        printf("\n");
    }
}
int main(){
    if(c1 == r2){
        input(x, r1, c1);
        input(y, r2, c2);

        display(x, r1, c1);
        display(y, r2, c2);

        computeproduct(x, y, product);
        printf("Multiplication matrix : \n");
        display(product, r1, c2);
    }
    else
        printf("product not possible.");
    
    return 0;
}
