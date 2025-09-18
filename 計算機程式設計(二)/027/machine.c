#include <stdio.h>
#include <stdlib.h>

int work_number_compare(int M,int work_number[10],int now_work_number[10]){
    for(int i=0;i<M;i++){
        if(work_number[i] != now_work_number[i]){
            return 1;
        }
    }
    return 0;
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
    int N,M;
    int work[10][10][2];
    int work_number[10];
    int now_work_number[10]={0};
    int work_hours[10] = {0};
    int machine[10] = {0};
    scanf("%d %d",&N,&M);
    getchar();
    for(int i=0;i<M;i++){
        scanf("%d",&work_number[i]);
        getchar();
        scanf("%d %d",&work[i][0][0],&work[i][0][1]);
        for(int j=1;j<work_number[i];j++){
            scanf(" %d %d",&work[i][j][0],&work[i][j][1]);
        }
    }

    while(work_number_compare(M,work_number,now_work_number)){
        int smallest_hours = 1000;
        int index;
        for(int i=0;i<M;i++){
            if(now_work_number[i] != work_number[i]){
                if(smallest_hours > max(machine[work[i][now_work_number[i]][0]],work_hours[i],work[i][now_work_number[i]][1])){
                    index = i;
                    smallest_hours = max(machine[work[i][now_work_number[i]][0]],work_hours[i],work[i][now_work_number[i]][1]);
                }
            }
        }
        machine[work[index][now_work_number[index]][0]] = work_hours[index] = smallest_hours;
        now_work_number[index]++;

    }
    int sum = 0;

    for(int i=0;i<M;i++){
        sum = sum + work_hours[i];
    }
    printf("%d",sum);
}
