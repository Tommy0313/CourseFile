#include<stdio.h>

int main(){
    int courseName[3];
    int courseNumber;
    int courseTime[3][3]={{0},{0}};
    int correct = 1;
    for(int i=0;i<3;i++){
        scanf("%d",&courseName[i]);
        getchar();
        scanf("%d",&courseNumber);
        getchar();
        for(int j=0;j<courseNumber;j++){
            scanf("%d",&courseTime[i][j]);
            getchar();
        }
    }

    for(int i=1;i<3;i++){
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(courseTime[0][x]==courseTime[i][y] && courseTime[0][x]!=0){
                    printf("%d,%d,%d\n",courseName[0],courseName[i],courseTime[0][x]);
                    correct = 0;
                }
            }
        }
    }

    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            if(courseTime[1][x]==courseTime[2][y] && courseTime[1][x]!=0){
                printf("%d,%d,%d\n",courseName[1],courseName[2],courseTime[1][x]);
                correct = 0;
            }
        }
    }
    if(correct==1)printf("correct");
}
