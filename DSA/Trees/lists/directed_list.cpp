#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    Node *link;

    Node() : key(0), link(NULL) {}
    Node(int val) : key(val), link(NULL) {}
    Node(int val, Node *ptr) : key(val), link(ptr) {}
};

struct SList : public Node {

private:
    Node *head;
    Node *tail;

public:
    SList() {
        head = new Node();
        tail = head;
    }
    // searches the node with given key 
    Node* search(int val) {
        Node* temp = head->link;
        while(temp != NULL) {
            if(val == temp->key)
                return temp;
            temp = temp->link;
        }
        return NULL;
    }
    // inserts a node after the given key
    void insert(int prev, int val) {
        Node *temp = search(prev);
        if(temp == NULL) return;
        Node *new_node = new Node(val, temp->link);
        temp->link = new_node;
        if(temp == tail)
            tail = tail->link;
    }
    // removes a node with given key
    void remove(int val) {
        Node* temp = head;
        while(temp->link != NULL && temp->link->key != val) {
            temp = temp->link;
        }
        if(tail == temp->link)
            tail = temp;
        
        if(temp != NULL) {
            Node *ptr = temp->link;
            temp->link = ptr->link;
            delete ptr;
        }
    }
    // appends a node in the beginning of the list 
    void pushft(int val) {
        Node *temp = head->link;
        head->link = new Node(val, temp);
    }
    // appends a node with given key
    void pushbk(int val) {
        (*tail).link = new Node(val);
        tail = tail->link;
    }
    // deletes a node from the beginning of the linked list
    void popft() {
        Node *temp = head->link;
        if(head->link == NULL) {
            printf("list is empty!!\n");
            return;
        }
        head->link = temp->link;
        delete temp;
    }
    // deletes a node from the end of the linked list
    void popbk() {
        Node *temp = head;
        if(head->link == NULL) {
            printf("list is empty!!\n");
            return;
        }
        while(temp->link->link != NULL)
            temp = temp->link;
        
        delete temp->link;
        tail = temp;
        tail->link = NULL;
    }
    // appends another list to the current list
    void append(SList ob) {
        tail->link = ob.head->link;
    }
    // resets a list
    void empty() {
        Node *ptr = head->link;
        tail = head;
        head->link = NULL;
        while(ptr != NULL) {
            Node *temp = ptr;
            ptr = ptr->link;
            delete temp;
        }
    }
    // reverses the linked list
    // void reverse() {
    //     Node *tmhd = head->link;

    //     Node *temp = (*tmhd).link;
    //     Node *next = (*temp).link;
    //     (*temp).link = NULL;

    //     while(next != NULL) {
    //         temp = next;
    //         next = (*temp).link;       //(*next).link
    //         (*temp).link = tmhd;
    //         tmhd = temp;
    //     }
    //     head->link = tmhd;
    // }
    // void display(){
    //     Node *temp = head;
    //     printf("List is : \n");
    //     while(temp != NULL){
    //         printf(" %d", (*temp).key);
    //         temp = (*temp).link;
    //     }
    //     printf("\n");
    // }
};

int main() {
    SList obb = SList();
    char args[16] = {0};
    int x;

    while(args[0]!='s' && args[1]!='t' && args[2]!='o' && args[3]!='p'){
        scanf(" %s", args);

        if(args[0] == 'p' && args[1] == 'f'){
            obb.popft();
        }
        else if(args[0] == 'p' && args[1] == 'b'){
            obb.popbk();
        }
        else if(args[0] == 'p'){
            scanf(" %d", &x);
            obb.remove(x);
        }
        else if(args[0] == 'f'){
            scanf(" %d", &x);
            obb.pushft(x);
        }
        else if(args[0] == 'b'){
            scanf(" %d", &x);
            obb.pushbk(x);
        }
        // else if(args[0]=='r'){
        //     obb.reverse();
        // }
        else{
            scanf(" %d", &x);
            obb.insert(atoi(args), x);
        }
        // obb.display();
    }
    return 0;
}
