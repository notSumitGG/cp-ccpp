#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct bracket{
    char data;
    struct bracket *link;
} bracket;

bracket *head = NULL;

void push(char value){
    bracket *temp = (bracket *)malloc(sizeof(bracket));
    (*temp).data = value;

    (*temp).link = head;
    head = temp;
}
void pop(){
    bracket *temp = head;

    head = (*temp).link;
    free(temp);
}
int check(char s[1000]){
    int len = strlen(s);
    for(int i=0; i<len; ++i){
        if(s[i]=='(' || s[i]=='<' || s[i]=='[' || s[i]=='{')    push(s[i]);

        else if(s[i]==')'){
            if(head == NULL)    return 0;
            else if((*head).data == '(')   pop();
            else        return 0;
        }
        else if(s[i]==']'){
            if(head == NULL)    return 0;
            else if((*head).data == '[')   pop();
            else        return 0;
        }
        else if(s[i]=='}'){
            if(head == NULL)    return 0;
            else if((*head).data == '{')   pop();
            else        return 0;
        }
        else if(s[i]=='>'){
            if(head == NULL)    return 0;
            else if((*head).data == '<')   pop();
            else        return 0;
        }
    }
    return 1;
}
int main(){
    char s[1000];
    scanf(" %s", s);
    if(check(s))
        printf("Balanced\n");
    else
        printf("Unbalanced\n");

    return 0;
}
