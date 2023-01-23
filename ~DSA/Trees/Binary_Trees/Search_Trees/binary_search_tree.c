#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key, freq;
    struct Node *left, *right;
    struct Node *parent;
};

struct Node *root = NULL;

struct Node *new_node(int data, struct Node *par){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    (*node).key = data;
    (*node).left = (*node).right = NULL;
    (*node).freq = 1;
    (*node).parent = par;

    return node;
}

void insert_val(int data, struct Node *node, struct Node *par){
    if(root == NULL)
        root = new_node(data, par);

    if((*node).key > data){
        if((*root).left == NULL){
            struct Node *temp = new_node(data, par);
            (*root).left = temp;
            return;
        }
        insert_val(data, (*node).left, node);
    }
    else if((*node).key < data){
        if((*root).right == NULL){
            struct Node *temp = new_node(data, par);
            (*root).right = temp;
            return;
        }
        insert_val(data, (*node).right, node);
    }
    else
        ++(*node).freq;
}
void insert(int data) {
    insert_val(data, root, NULL);
}

struct Node* search(int data, struct Node *node){
    if (node == NULL || (*node).key == data)
       return node;

    if((*node).key < data)
        search(data, (*node).right);
    else
        search(data, (*node).left);
}

struct Node* next(int data){
    struct Node *node = search(data, root);

    if(node->right != NULL)
        return left_descendent(node->right);
    else 
        return right_ancestor(node, node->key);
}

struct Node* previous(int data) {
    struct Node *node = search(data, root);

    if(node->left != NULL)
        return right_descendent(node->left);
    else 
        return left_ancestor(node, node->key);
}

struct Node* left_descendent(struct Node *node) {
    while(node->left != NULL)
        node = node->left;
        
    return node;
}
struct Node* right_descendent(struct Node *node) {
    while(node->right != NULL)
        node = node->right;

    return node;
}

struct Node* left_ancestor(struct Node *node, int data) {
    while(node->key <= data)
        node = node->parent;
    
    return node;
}
struct Node* right_ancestor(struct Node *node, int data) {
    while(node->key >= data)
        node = node->parent;

    return node;
}
