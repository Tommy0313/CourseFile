#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node_s {
int data;
struct node_s * next;
}node_t;
typedef node_t * nodep_t;

nodep_t create(int data){
    nodep_t newNode;
    newNode= (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(nodep_t *rear,nodep_t *tail, int data){
    nodep_t temp = create(data);
    if(*rear == NULL){
        *rear = temp;
        *tail = temp;
    }
    else{
        (*tail)->next = temp;
        *tail = temp;
    }
}

void pop(nodep_t *rear,nodep_t *tail){
    if((*rear) == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n",(*rear)->data);
        (*rear) = (*rear)->next;
    }
}

void front(nodep_t p){
    if(p == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n",p->data);
    }
}

void empty(nodep_t *rear,nodep_t *tail){
    if(*rear == NULL){
        printf("Queue is empty\n");
    }
    else{
        *rear = NULL;
        *tail = NULL;
    }
}

void print(nodep_t p){
    if(p == NULL){
        printf("Queue is empty\n");
    }
    else{
        while(p != NULL){
            printf("%d\n",p->data);
            p = p->next;
        }
    }
}

int main(){
    int N,data;
    char temp[6];
    nodep_t rear = NULL;
    nodep_t tail = NULL;
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%s",temp);
        if(strcmp(temp,"push") == 0){
            scanf(" %d",&data);
        }
        getchar();

        if(strcmp(temp,"push") == 0){
            push(&rear,&tail,data);
        }
        else if(strcmp(temp,"pop") == 0){
            pop(&rear,&tail);
        }
        else if(strcmp(temp,"front") == 0){
            front(rear);
        }
        else if(strcmp(temp,"empty") == 0){
            empty(&rear,&tail);
        }
        else if(strcmp(temp,"print") == 0){
            print(rear);
        }
    }

}
