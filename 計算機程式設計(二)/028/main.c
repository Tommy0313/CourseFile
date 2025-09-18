#include <stdio.h>
#include <stdlib.h>

typedef struct work_s{
    int wait_work[10];
    int wait_work_number;
    int hours;
}work_t;

int work_process(work_t work[101],int work_index,int now_hours,int *max_hours){
    if(work[work_index].hours+now_hours > *max_hours){
        *max_hours = work[work_index].hours+now_hours;
    }
    for(int i=0;i<work[work_index].wait_work_number;i++){
        work_process(work,work[work_index].wait_work[i],work[work_index].hours+now_hours,max_hours);
    }

}

int max(int machine_hours,int working_hours, int work_hours){
    if(machine_hours> working_hours){
        return machine_hours + work_hours;
    }
    else{
        return working_hours + work_hours;
    }
}

int main(){
    int N,M,K;
    scanf("%d",&N);
    getchar();
    work_t work[N][101];
    int work_M[N];
    for(int i=0;i<N;i++){
        scanf("%d",&M);
        getchar();
        work_M[i] = M;
        for(int j=1;j<M+1;j++){
            scanf("%d",&work[i][j].hours);
            scanf(" %d",&K);
            work[i][j].wait_work_number = K;
            for(int k=0;k<K;k++){
                scanf(" %d",&work[i][j].wait_work[k]);
            }
            getchar();
        }
    }


    for(int i=0;i<N;i++){
        int max_hours = 0;
        for(int j=0;j<work_M[i];j++){
            work_process(work[i],j+1,0,&max_hours);
        }
        printf("%d\n",max_hours);
    }

}
