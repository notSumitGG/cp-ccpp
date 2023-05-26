#include<stdio.h>

struct Node{
    int key;
    struct Node *left, *right;
    struct Node *parent;
};
struct Node *root = NULL;

void preOrder(struct Node *node){
    if(node == NULL)
        return;

    printf(" %d", (*node).key);
    preOrder((*node).left);
    preOrder((*node).right);
}
void inOrder(struct Node *node){
    if(node == NULL)
        return;

    preOrder((*node).left);
    printf(" %d", (*node).key);
    preOrder((*node).right);
}
void postOrder(struct Node *node){
    if(node == NULL)
        return;

    preOrder((*node).left);
    preOrder((*node).right);
    printf(" %d", (*node).key);
}
