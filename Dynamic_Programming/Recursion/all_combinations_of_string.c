#include <stdio.h>

void combine(char s[], int i, char x[]) {
	if(strlen(s) == i) {
		printf(" %s ", x);
		return;
	}
	combine(s, i + 1, strcat(x, s[i]));
	combine(s, i + 1, x);
}
void main(){
    char str[100];
    printf("Enter a string : ");
    scanf(" %s\n", str);
    
    combine(str, 0, "");
}