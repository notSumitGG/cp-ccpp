#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

typedef struct Node{
    int key;
    struct Node *left, *right;
    struct Node *parent;
} Node;

Node *root = NULL;
int ht[10000], dh[10000];
Node *ref[10000];

int max(int x, int y) {
    if(x > y) return x;
    else return y;
}

// finds and initializes depth and height of each node to an array
void find_dht(Node *node = root) {
    if(node->left == NULL && node->right == NULL) {
        ht[node->key] = 0;
        return;
    } else {
        if(node->left != NULL) {
            dh[node->left->key] = dh[node->key] + 1;
            find_dht(node->left);
            ht[node->key] = max(ht[node->key],ht[node->left->key]+1);
        }
        if(node->right != NULL) {
            dh[node->right->key] = dh[node->key] + 1;
            find_dht(node->right);
            ht[node->key] = max(ht[node->key],ht[node->right->key]+1);
        }
    }
}
int depth(int key) {
    if(dh[0] != 1){
        find_dht();
        dh[0] = ht[0] = 1;  // checker that keeps depth of each node in sync
    }
    return dh[key];
}
int height(int key) {
    if(ht[0] != 1){
        find_dht();
        dh[0] = ht[0] = 1;  // checker that keeps height of each node in sync
    }
    return dh[key];
}

vector<int> path(int key){
    Node* node = ref[key];
    vector<int> v;
    while(node != NULL) {
        v.push_back(node->key);
        node = node->parent;
    }
    return v;
}
Node* lca(int key1, int key2){
    vector<int> p1 = path(key1);
    vector<int> p2 = path(key2);
    vector<int> :: iterator i1 = p1.end()-1;
    vector<int> :: iterator i2 = p1.end()-1;
    while(*i1 == *i2){
        --i1;
        --i2;
    }
    return ref[*(++i1)];
}

Node* new_node(int data, struct Node *par) {
    Node *node = (Node *)malloc(sizeof(Node));
    (*node).key = data;
    (*node).left = NULL;
    (*node).right = NULL;
    (*node).parent = par;

    return ref[data] = node;
}
void insert(int x, int y) {
    if(root == NULL) {
        root = new_node(x, NULL);
        dh[x] = 0;
    }
    Node *xnode = ref[x];
    // left child first
    if(xnode->left == NULL) {
        xnode->left = new_node(y, xnode);
    } else if(xnode->right == NULL) {
        xnode->right = new_node(y, xnode);
    }
}

void dfs(Node *node = root) {
    if(node->left == NULL && node->right == NULL)   return;
    else {
        if(node->left != NULL)
            dfs(node->left);
        if(node->right != NULL)
            dfs(node->right);
    }
}