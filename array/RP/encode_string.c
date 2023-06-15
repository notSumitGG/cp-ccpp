#include<stdio.h>
#include<string.h>
//day 1 q4
//If input: aaaabbBccdee Then Output: A4B2b1C2D1E2

void encode(char str[], char enstr[]){
    int i = 1, j = 0, count = 1;
    strcat(str, " ");
    while(str[i] != NULL){
        if(str[i - 1] == str[i])
            count++;
        else{
            enstr[j] = str[i - 1];
            j++;
            enstr[j] = count + 48;
            j++;
            count = 1;
        }
        i++;
    }
}
int main(){
    char str[100], enstr[100];
    printf("Enter a string : ");
    scanf(" %s", str);

    encode(str, enstr);
    printf("Encoded String : %s", enstr);

    return 0;
}