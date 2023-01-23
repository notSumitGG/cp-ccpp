#include<stdio.h>
#include<math.h>
#define N 4
#define M 4

void input(int x[N][M]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++)
            scanf(" %d", &x[i][j]);
    }
}
void display(int x[N][M]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++)
            printf(" %d", x[i][j]);
        printf("\n");
    }
}
int trace(int x[N][M]){
    int i, j, tr = 0;
    for(i = 0; i < min(N, M); i++)
        tr = tr + x[i][i];
    
    return tr;
}
int main(){
    int x[N][M], y[N][M], sum[N][M], diff[N][M];
    input(x);
    input(y);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            sum[i][j] = x[i][j] + y[i][j];
            diff[i][j] = x[i][j] - y[i][j];
        }
    }
    printf("Addition matrix : \n");
    display(sum);
    printf("Substraction matrix : \n");
    display(diff);

    return 0;
}