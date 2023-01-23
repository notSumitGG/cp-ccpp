#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *head = NULL;
struct Node *tail = NULL;
int size = 0;

void pushfront(int value){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node).data = value;

    (*new_node).right = head;
    (*new_node).left = NULL;

    if(head != NULL)
        (*head).left = new_node;
    else                                // tail == NULL
        tail = new_node;

    head = new_node;
    ++size;
}
void pushback(int value){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node).data = value;

    (*new_node).left = tail;
    (*new_node).right = NULL;

    if(tail != NULL)
        (*tail).right = new_node;
    else                                // head == NULL
        head = new_node;

    tail = new_node;
    ++size;
}
void insert(int value, int index){
    if(index == 0){
        pushfront(value);
        return;
    }
    else if(index == size){
        pushback(value);
        return;
    }
    else {
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        (*new_node).data = value;

        if(index <= size/2) {
            struct Node *temp = head;
            for(int i=0; i < index - 1; ++i)
                temp = (*temp).right;

            (*new_node).left = temp;
            (*new_node).right = (*temp).right;
            (*(*temp).right).left = new_node;
            (*temp).right = new_node;

        } else {
            struct Node *temp = tail;
            for(int i=size-1; i >= index + 1; --i)
                temp = (*temp).left;

            (*new_node).right = temp;
            (*new_node).left = (*temp).left;
            (*(*temp).left).right = new_node;
            (*temp).left = new_node;
        }
        ++size;
    }
}

void popfront(){
    struct Node *temp = head;

    if(head == NULL)    return;

    head = (*head).right;
    (*head).left = NULL;
    free(temp);
    --size;
}
void popback(){
    struct Node *temp = tail;

    if(tail == NULL)    return;

    tail = (*tail).left;
    (*tail).right = NULL;
    free(temp);
    --size;
}
void delete(int index){
    if(index == 0){
        popfront();
        return;
    }
    else if(index == size-1){
        popback();
        return;
    }
    else{
        struct Node *temp;
        if(index <= size/2){
            temp = head;
            for(int i=0; i < index - 1; ++i)
                temp = (*temp).right;

            struct Node *temp1 = (*temp).right;
            (*temp).right = (*temp1).right;
            (*(*temp).right).left = temp;
            free(temp1);
        } else {
            temp = tail;
            for(int i=size-1; i >= index + 2; --i)
                temp = (*temp).left;

            struct Node *temp1 = (*temp).left;
            (*temp).left = (*temp1).left;
            (*(*temp).left).right = temp;
            free(temp1);
        }
        --size;
    }
}
void reverse(){
    struct Node *temp = head;
    head = tail;
    tail = temp;
}
void print(){
    struct Node *temp = head;
    printf("List is : ");
    while(temp != NULL){
        printf(" %d", (*temp).data);
        temp = (*temp).right;
    }
    printf("\n");
}
int toInteger(char data[]){
    int i = 1, res = 0;
    while(data[i] >= 48 && data[i] <= 57){
        res = res * 10 + (data[i] - 48);
        ++i;
    }
    return res;
}
int main(){
    char data[16] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    int position, x;

    while(1){
        scanf(" %s", data);

        if(data[0]=='s' && data[1]=='t' && data[2]=='o' && data[3]=='p'){
            break;
        }
        else if(data[0] == 'r'){
            reverse();
        }
        else if(data[0] == 'p' && data[1] == 'f'){
            popfront();
        }
        else if(data[0] == 'p' && data[1] == 'b'){
            popback();
        }
        else if(data[0] == 'p'){
            scanf(" %d", &position);
            delete(position);
        }
        else if(data[0] == 'f'){
            x = toInteger(data);
            pushfront(x);
        }
        else if(data[0] == 'b'){
            x = toInteger(data);
            pushback(x);
        }
        else{
            x = atoi(data);
            scanf(" %d", &position);
            insert(x, position);
        }
        print();
        // printf(" (%d) ", size);
    }
    return 0;
}
