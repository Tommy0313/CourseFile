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

void push(nodep_t *p, int data){
    nodep_t temp = create(data);
    temp->next = *p;
    *p = temp;
}

void pop(nodep_t *p){
    if((*p) == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n",(*p)->data);
        (*p) = (*p)->next;
    }
}

void top(nodep_t p){
    if(p == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n",p->data);
    }
}

void empty(nodep_t *p){
    if(*p == NULL){
        printf("Stack is empty\n");
    }
    else{
        *p = NULL;
    }
}

void print(nodep_t p){
    if(p == NULL){
        printf("Stack is empty\n");
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
    nodep_t stack = NULL;
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%s",temp);
        if(strcmp(temp,"push") == 0){
            scanf(" %d",&data);
        }
        getchar();

        if(strcmp(temp,"push") == 0){
            push(&stack,data);
        }
        else if(strcmp(temp,"pop") == 0){
            pop(&stack);
        }
        else if(strcmp(temp,"top") == 0){
            top(stack);
        }
        else if(strcmp(temp,"empty") == 0){
            empty(&stack);
        }
        else if(strcmp(temp,"print") == 0){
            print(stack);
        }
    }

}
