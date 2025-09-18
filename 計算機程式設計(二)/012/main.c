#include <stdio.h>

int hitToInt(char word){
    if(word == 'H'){
        return 4;
    }
    else if(word == 'O'){
        return 0;
    }
    else{
        return word-48;
    }
}

int calculateScoreRank(int rank[3*3], char player_hit_result[9*5],int total_hit_numbers,int out_numbers){
    int run_situation[4]={0};
    int result[2*9] = {0};
    int now_out_numbers = 0,now_total_numbers=0,now_player_numbers = 0,runs,get_score_player_number,now_scores=0,max_player,max_result,rank_number = 0;
    while(now_total_numbers < total_hit_numbers){
        now_player_numbers = now_total_numbers % 9;
        runs = hitToInt(player_hit_result[now_total_numbers%9*5+now_total_numbers/9]);
        if(runs == 0){
            now_out_numbers += 1;
            if(now_out_numbers % 3 == 0){
                for(int i=0;i<4;i++){
                    run_situation[i]=0;
                }
            }
            if(now_out_numbers == out_numbers){
                break;
            }
        }
        else{
            result[now_player_numbers*2] += 1;
            for(int i=0;i<runs;i++){
                get_score_player_number = run_situation[3];
                run_situation[3] = run_situation[2];
                run_situation[2] = run_situation[1];
                if(i==0){
                    run_situation[1] = now_player_numbers+1;
                    run_situation[0] = 0;
                }
                else{
                    run_situation[1] = 0;
                    run_situation[0] = 0;
                }
                for(int j=0;j<4;j++){
                    if(run_situation[j]!=0){
                        result[(run_situation[j]-1)*2+1] += 1;
                    }
                }
                if(get_score_player_number != 0){
                    now_scores += 1;
                    result[(get_score_player_number-1)*2+1] += 1;
                }
            }
        }
        now_total_numbers ++;
    }

    for(int j = 0; j<3;j++){
        max_result = 0;
        for(int i = 0;i<9;i++){
            if(result[i*2+1]>max_result){
                max_result= result[i*2+1];
                max_player = i;
            }
        }
        rank[rank_number*3]=max_player+1;
        rank[rank_number*3+1]=result[max_player*2];
        rank[rank_number*3+2]=result[max_player*2+1];
        result[max_player*2+1] = 0;
        rank_number++;
    }


    return now_scores;
}

int main(){
    int player_number=0,total_hit_numbers = 0,out_numbers,hit_numbers;
    char player_hit_result[9*5];
    int rank[3*3];
    for(;player_number<9;player_number++){
        scanf("%d",&hit_numbers);
        total_hit_numbers += hit_numbers;
        for (int i = 0; i < hit_numbers; i++) {
            scanf(" %c", &player_hit_result[i+player_number*5]);
        }
        getchar();
    }
    scanf("%d",&out_numbers);
    getchar();
    printf("%d\n",calculateScoreRank(rank,player_hit_result,total_hit_numbers,out_numbers));



    for(int i=0;i<3;i++){
        printf("%d %d %d\n",rank[i*3],rank[i*3+1],rank[i*3+2]);
    }
}
