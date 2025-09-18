#include<stdio.h>

int team(char team){
    switch(team){
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
    }

}

int main(){
    int number,team1,team2,team1_point,team2_point,team1_bureau_point,team2_bureau_point;
    char first_team,second_team;
    int win[3]={0},total_point[3]={0};
    scanf("%d",&number);
    getchar();
    for(int i=0;i<number;i++){
        team1_bureau_point=0;
        team2_bureau_point=0;
        scanf("%c %c",&first_team,&second_team);
        getchar();
        team1 = team(first_team);
        team2 = team(second_team);
        for(int j=0;j<4;j++){
            scanf("%d %d",&team1_point,&team2_point);
            getchar();
            team1_bureau_point += team1_point;
            team2_bureau_point += team2_point;
        }
        total_point[team1] += team1_bureau_point;
        total_point[team2] += team2_bureau_point;
        if(team1_bureau_point>team2_bureau_point)win[team1]+=1;
        else win[team2]+=1;
    }
    if(win[0]>win[1] && win[0]>win[2]){
        printf("A\n");
        printf("%d",total_point[0]);
    }
    else if(win[1]>win[0] && win[1]>win[2]){
        printf("B\n");
        printf("%d",total_point[1]);
    }
    else{
        printf("C\n");
        printf("%d",total_point[2]);
    }
}
