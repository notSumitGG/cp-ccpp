#include<stdio.h>
#include<string.h>

int length(char s[], int high){
    int low = 0, mid;
    
    while(low <= high){
        mid = low + (high - low)/2;
        printf(" %d\n", mid);
        if(s[mid] == '\0')
            high = mid - 1;
        else if(s[mid] != '\0')
            low = mid + 1;
    }
    return low;
}
int main(){
    char s[10000];
    memset(s, '\0', 10000);
    scanf(" %s", s);
    int len = length(s, sizeof(s));
    printf(" %d\n", len);
    return 0;
}
