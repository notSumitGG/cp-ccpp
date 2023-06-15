#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node *link;
} Node;

Node *head = NULL;
Node *tail = NULL;

void push(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    (*new_node).key = data;
    (*new_node).link = NULL;

    if(head == NULL)    head = new_node;
    else    (*tail).link = new_node;
    
    tail = new_node;
}
void pop(){
    Node *temp = head;
    head = (*temp).link;
    free(temp);
    if(head == NULL)
        tail = NULL;
}
