#include<stdio.h>
#include<string.h>

//using main formula for combinations
long binomial_cofficient(int n, int r){
    double c=1.0;

    if(r > n-r)
        r = n-r;

    for(int i=0; i<r; ++i){
        c*=(n-i);
        c/=(i+1);
    }
    return c;
}
void using_combinations(int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<=i; ++j)
            printf(" %ld\t", binomial_cofficient(i, j));
        printf("\n");
    }
}

//using auxliary matrix to store values
void using_auxliary_array(int n){
    int aux[100][100];
    memset(aux, 0, sizeof(aux));

    aux[0][1] = 1;
    printf(" %d\n", aux[0][1]);
    for(int i=1; i<n; ++i){
        for(int j=1; j<=i+1; ++j){
            aux[i][j] = aux[i-1][j-1] + aux[i-1][j];
            printf(" %d\t", aux[i][j]);
        }
        printf("\n");
    }
}

//using binomial coefficient series changing pattern
void binomial_coefficient_series(int n){
    for(int line=1; line<=n; ++line){
        int c=1;
        for(int i=1; i<=line; ++i){
            printf(" %d\t", c);
            c = c * (line - i)/(i);
        }
        printf("\n");
    }
}
int main(void){
    int n;
    scanf(" %d", &n);
    binomial_coefficient_series(n);
    return 0;
}
/*
1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10  10  5   1
1   6   15  20  15  6   1
1   7   25  35  35  21  7   1
*/
