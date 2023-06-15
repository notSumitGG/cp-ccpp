#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
} Node;

Node *head = NULL;

void push(int x){
    Node *new_node = (Node*)malloc(sizeof(Node));
    (*new_node).data = x;

    (*new_node).link = head;
    head = new_node;
}
void pop(){
    Node *temp = head;

    head = (*temp).link;
    free(temp);
}
