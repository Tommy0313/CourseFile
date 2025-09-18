#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
int data;
struct dnode_s * front;
struct dnode_s * back;
} node_t;
typedef node_t * nodep_t;

nodep_t create(int data){
    nodep_t newNode;
    newNode= (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->front = NULL;
    newNode->back = NULL;
    return newNode;
}

void addFront(nodep_t *rear,nodep_t *tail, int data){
    nodep_t temp = create(data);
    if(*rear == NULL){
        *rear = temp;
        *tail = temp;
    }
    else{
        (*rear)->front = temp;
        temp->back = *rear;
        *rear = temp;
    }
}

void addBack(nodep_t *rear,nodep_t *tail, int data){
    nodep_t temp = create(data);
    if(*rear == NULL){
        *rear = temp;
        *tail = temp;
    }
    else{
        (*tail)->back = temp;
        temp->front = *tail;
        *tail = temp;
    }
}

void removeFront(nodep_t *rear,nodep_t *tail){
    if((*rear) == NULL){
        printf("Double link list is empty\n");
    }
    else{
        (*rear) = (*rear)->back;
        (*rear)->front = NULL;
    }
}

void removeBack(nodep_t *rear,nodep_t *tail){
    if((*tail) == NULL){
        printf("Double link list is empty\n");
    }
    else{
        (*tail) = (*tail)->front;
        (*tail)->back = NULL;
    }
}

void empty(nodep_t *rear,nodep_t *tail){
    if(*rear == NULL){
        printf("Double link list is empty\n");
    }
    else{
        *rear = NULL;
        *tail = NULL;
    }
}

void insert(nodep_t *rear,int index,int data){
    nodep_t temp = create(data);
    nodep_t current = *(rear);
    nodep_t previous;
    for(int i=1;i<= index;i++){
        previous = current;
        current = current->back;

        if(current == NULL){
            printf("Invalid command\n");
            break;
        }
        if(index == 1){
            previous->back = temp;
            temp->front = previous;
            current->front = temp;
            temp->back = current;
            break;
        }
        if(i==index){
            previous->back = temp;
            temp->front = previous;
            current->front = temp;
            temp->back = current;
            break;
        }
    }
}

void remove1(nodep_t *rear,int index){
    nodep_t current = *(rear);
    nodep_t previous;
    for(int i=1;i<= index;i++){
        if(current == NULL){
            printf("Invalid command\n");
            break;
        }
        if(i==index){
            if(current->back == NULL){
                previous->back = NULL;
            }
            else{
                previous->back = current->back;
                current->back->front = previous;
            }
            break;
        }
        previous = current;
        current = current->back;
    }
}

void print(nodep_t p){
    if(p == NULL){
        printf("Double link list is empty\n");
    }
    else{
        while(p != NULL){
            printf("%d\n",p->data);
            p = p->back;
        }
    }
}

int main(){
    int N,data,index;
    char temp[20];
    nodep_t rear = NULL;
    nodep_t tail = NULL;
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%s",temp);
        if(strcmp(temp,"addBack") == 0 || strcmp(temp,"addFront") == 0){
            scanf(" %d",&data);
        }
        else if(strcmp(temp,"insert") == 0){
            scanf(" %d %d",&index,&data);
        }
        else if(strcmp(temp,"remove") == 0){
            scanf(" %d",&index);
        }
        getchar();

        if(strcmp(temp,"addFront") == 0){
            addFront(&rear,&tail,data);
        }
        else if(strcmp(temp,"addBack") == 0){
            addBack(&rear,&tail,data);
        }
        else if(strcmp(temp,"removeFront") == 0){
            removeFront(&rear,&tail);
        }
        else if(strcmp(temp,"removeBack") == 0){
            removeBack(&rear,&tail);
        }
        else if(strcmp(temp,"empty") == 0){
            empty(&rear,&tail);
        }
        else if(strcmp(temp,"insert") == 0){
            insert(&rear,index,data);
        }
        else if(strcmp(temp,"remove") == 0){
            remove1(&rear,index);
        }
        else if(strcmp(temp,"print") == 0){
            print(rear);
        }
    }

}
