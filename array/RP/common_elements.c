#include<stdio.h>
//day3 q4
//three arrays sorted in non-decreasing order, print all common elements in these arrays
int main(){
    int a[50], b[50], c[50];
    int n1=0, n2=0, n3=0;
    int i, j, k;

    /*int a[] = {1, 5, 10, 20, 40, 80};
    int b[] = {6, 7, 20, 80, 100};
    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    n1=6;
    n2=5;
    n3=8;*/

    scanf(" %d %d %d", &n1, &n2, &n3);
    for(i=0; i < n1; ++i)
        scanf(" %d", &a[i]);
    for(j=0; j < n2; ++j)
        scanf(" %d", &a[j]);
    for(k=0; k < n1; ++k)
        scanf(" %d", &a[k]);

    i=0; j=0; k=0;

    while(i < n1 && j < n2 && k < n3){
        if(a[i]==b[j] && b[j]==c[k]){
            printf(" %d\t", a[i]);
            ++i;
            ++j;
            ++k;
        }

        if(a[i]<b[j] && a[i]<c[k])
            ++i;
        else if(b[j]<a[i] && b[j]<c[k])
            ++j;
        else if(c[k]<b[j] && c[k]<a[i])
            ++k;
    }
    return 0;
}
