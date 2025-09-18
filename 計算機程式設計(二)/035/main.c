#include <stdio.h>
#include <stdlib.h>

typedef struct work_s{
    int wait_work[10];
    int wait_work_number;
    int hours;
}work_t;

typedef struct node_s{
int time;
int waiteNodeNum;
int waiteNode[100];
struct node_s* next;
}node_t;
typedef node_t* nodep;

nodep searchRoot(nodep root,int index){
    for(int i=1;i<index;i++){
        root = root->next;
    }

    return root;
}

int in(int throughed_number[101],int number){
    for(int i=1;i<=throughed_number[0];i++){
        if(throughed_number[i] == number){
            return 1;
        }
    }
    return 0;
}

int work_process(nodep root,nodep current,int throughed_number[101],int number,int now_hours,int *max_hours){
    throughed_number[0]++;
    throughed_number[throughed_number[0]] = number;
    if(current->time+now_hours > *max_hours){
        *max_hours = current->time+now_hours;
    }
    if(current->waiteNodeNum != 0){
        for(int i=0;i<current->waiteNodeNum;i++){
            if(in(throughed_number,current->waiteNode[i])==0){
                work_process(root,searchRoot(root,current->waiteNode[i]),throughed_number,current->waiteNode[i],current->time+now_hours,max_hours);
            }
        }
    }
    throughed_number[0]--;
}


nodep create(int time){
    nodep newNode=(nodep)malloc(sizeof(node_t));
    newNode->time = time;
    newNode->waiteNodeNum = 0;
    newNode->next = NULL;
    return newNode;
}

nodep createWork(int M){
    nodep root = NULL;
    nodep current,temp;
    for(int i=0;i<M;i++){
        if(root == NULL){
            root = create(0);
            current = root;
        }
        else{
            current->next = create(0);
            current = current->next;
        }
    }
    return root;
}

void search(nodep root, int index,int time){
    nodep current = root;
    for(int i=1;i<index;i++){
        current = current->next;
    }
    current->waiteNode[current->waiteNodeNum] = time;
    current->waiteNodeNum++;
}


int main(){
    int N,M,K,index;
    int time;
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        nodep root;
        nodep current;

        scanf("%d",&M);
        getchar();
        root = createWork(M);
        current = root;
        for(int j=1;j<M+1;j++){

            scanf("%d",&time);
            current->time = time;

            scanf(" %d",&K);
            for(int k=0;k<K;k++){
                scanf(" %d",&index);
                search(root,index,j);
            }
            getchar();
            current = current->next;
        }
        int max_hours = 0;
        current = root;

        int throughed_number[101];

        for(int j=1;j<M+1;j++){
            throughed_number[0] = 0;
            work_process(root,current,throughed_number,j,0,&max_hours);
            current=current->next;
        }
        printf("%d\n",max_hours);
    }

}
