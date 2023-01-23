#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    Node *link;
} Node;

Node *head = NULL;

void insert(int x, int pos){
    Node *new_node = (Node *)malloc(sizeof(Node));
    (*new_node).key = x;

    if(pos == 0){
        (*new_node).link = head;
        head = new_node;
        return;
    }
    Node *temp = head;
    for(int i = 1; i <= pos - 1; i++)
        temp = (*temp).link;

    (*new_node).link = (*temp).link;
    (*temp).link = new_node;

}
void delete(int pos){
    Node *temp = head;

    if(pos == 0){
        head = (*head).link;
        free(temp);
        return;
    }
    for(int i = 0; i < pos - 2; i++)
        temp = (*temp).link;

    Node *temp1 = (*temp).link;
    (*temp).link = (*temp1).link;
    free(temp1);
}
void pushfront(int x){
    Node *new_node = (Node*)malloc(sizeof(Node));
    (*new_node).key = x;

    (*new_node).link = head;
    head = new_node;
}
void pushback(int x){
    Node *new_node = (Node*)malloc(sizeof(Node));
    (*new_node).key = x;

    Node *temp = head;
    while((*temp).link != NULL)
        temp = (*temp).link;

    (*temp).link = new_node;
    (*new_node).link = NULL;
}
void popfront(){
    Node *temp = head;

    head = (*temp).link;
    free(temp);
}
void popback(){
    Node *temp = head, *tem1;
    while((*tem1).link != NULL){
        temp = (*temp).link;
        tem1 = (*temp).link;
    }

    free(tem1);
    (*temp).link = NULL;
}
void display(){
    Node *temp = head;
    printf("List is : \n");
    while(temp != NULL){
        printf(" %d", (*temp).key);
        temp = (*temp).link;
    }
    printf("\n");
}
int toInteger(char key[]){
    int i = 1, res = 0;
    while(key[i] >= 48 && key[i] <= 57){
        res = res * 10 + (key[i] - 48);
        ++i;
    }
    return res;
}
int main(){
    char args[16] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    int x;

    while(args[0]!='s' && args[1]!='t' && args[2]!='o' && args[3]!='p'){
        scanf(" %s", args);

        if(args[0] == 'p' && args[1] == 'f'){
            popfront();
        }
        else if(args[0] == 'p' && args[1] == 'b'){
            popback();
        }
        else if(args[0] == 'p'){
            scanf(" %d", &x);
            delete(x);
        }
        else if(args[0] == 'f'){
            scanf(" %d", &x);
            pushfront(x);
        }
        else if(args[0] == 'b'){
            scanf(" %d", &x);
            pushback(x);
        }
        else{
            scanf(" %d", &x);
            insert(atoi(args), x);
        }
        display();
    }
    return 0;
}

// DEQUEUE
// int main(){
//     char key[20], type = 1;
//
//     scanf(" %s", key);
//     while(key[0]!='s' && key[1]!='t' && key[2]!='o' && key[3]!='p'){
//
//         if(key[0]=='f')
//             type = 1;
//         else if(key[0]=='r')
//             type = 2;
//         else if(key[0]=='p' && key[1]=='f'){      //pop front
//             popfront();
//             display();
//         }
//         else if(key[0]=='p' && key[1]=='r'){      //pop rear
//             poprear();
//             display();
//         }
//
//         else if(type == 1){                         //push front
//             int temp=atoi(key);
//             pushfront(temp);
//             display();
//         }
//         else if(type == 2){                         //push rear
//             int temp=atoi(key);
//             pushrear(temp);
//             display();
//         }
//         scanf(" %s", key);
//     }
//     return 0;
// }

// QUEUE
// int main(){
//     char key[10000];
//
//     scanf(" %s", key);
//     while(key[0]!='s' && key[1]!='t' && key[2]!='o' && key[3]!='p'){
//         if(key[0]=='P' || key[0]=='p'){
//                 poprear();
//                 display();
//         }
//         else{
//             int temp=atoi(key);
//             pushfront(temp);
//             display();
//         }
//         scanf(" %s", key);
//     }
//     return 0;
// }

// STACK
// int main(){
//     char key[10];
//
//     scanf(" %s", key);
//     while(key[0]!='s' && key[1]!='t' && key[2]!='o' && key[3]!='p'){
//         if(key[0]=='P' || key[0]=='p'){
//             popfront();
//             display();
//         }
//         else{
//             int temp=atoi(key);
//             pushfront(temp);
//             display();
//         }
//         scanf(" %s", key);
//     }
//     return 0;
// }
