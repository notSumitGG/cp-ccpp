#include<stdio.h>
#include<string.h>

void substring(char s[], int start, int end){
	char ch[end - start + 1];
	int i = 0;
	while(i + start <= end){
		ch[i] = s[start + i];
		i++;
	}
}
void permute(char s[], char x[]) {
	if(strlen(s) == 0) {
		printf(" %s ", x);
		return;
	}
	for(int j = 0; j < strlen(s); j++){
		char firstpart[] = substring(s, 0, i);
		char lastpart[] = substring(s, i + 1, strlen(s) - 1);
		permute(strcat(firstpart, lastpart), x + s[i]);
	}
}
void main(){
    char str[100];
    printf("Enter a string : ");
    scanf(" %s\n", str);
    
    permute(str, "");
}