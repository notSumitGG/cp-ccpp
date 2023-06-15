#include<stdio.h>
#include<stdlib.h>

struct Node {
    int key, freq;
    struct Node *left, *right;
    struct Node *parent;

    Node() {}
    Node(int val, struct Node *par): key(val), freq(1), left(NULL), right(NULL), parent(par) {}
};

struct BST: public Node {
    
private:
    Node *root;

public:
    BST(): root(NULL) {}

    struct Node *new_node(int val, Node *par) {
        Node *node = new Node(val, par);
        return node;
    }
protected:
    void insert_val(int val, Node *node, Node *par) {
        if(root == NULL)
            root = new_node(val, par);

        if((*node).key > val){
            if((*root).left == NULL){
                Node *temp = new_node(val, par);
                (*root).left = temp;
                return;
            }
            insert_val(val, (*node).left, node);
        }
        else if((*node).key < val){
            if((*root).right == NULL){
                Node *temp = new_node(val, par);
                (*root).right = temp;
                return;
            }
            insert_val(val, (*node).right, node);
        }
        else
            ++(*node).freq;
    }
public:
    void insert(int val) {
        insert_val(val, root, NULL);
    }
protected:
    int find_height(Node *ptr) {
        if(root == NULL) return 0;
        int h_left = find_height(ptr->left);
        int h_right = find_height(ptr->right);
        if(h_left > h_right)
            return 1 + h_left;
        else 
            return 1 + h_right;
    }
public:
    int height() {
        return find_height(root);
    }
    Node* search(int val, Node *node){
        if (node == NULL || (*node).key == val)
        return node;

        if((*node).key < val)
            search(val, (*node).right);
        else
            search(val, (*node).left);
    }
    // finds next greater element in the search tree
    Node* next(int val){
        struct Node *node = search(val, root);

        if(node->right != NULL)
            return left_descendent(node->right);
        else 
            return right_ancestor(node, node->key);
    }
    // finds previous lesser element in the search tree
    Node* previous(int val) {
        struct Node *node = search(val, root);

        if(node->left != NULL)
            return right_descendent(node->left);
        else 
            return left_ancestor(node, node->key);
    }

    Node* left_descendent(Node *node) {
        while(node->left != NULL)
            node = node->left;
            
        return node;
    }
    Node* right_descendent(Node *node) {
        while(node->right != NULL)
            node = node->right;

        return node;
    }

    Node* left_ancestor(Node *node, int val) {
        while(node->key <= val)
            node = node->parent;
        
        return node;
    }
    Node* right_ancestor(Node *node, int val) {
        while(node->key >= val)
            node = node->parent;

        return node;
    }
};
