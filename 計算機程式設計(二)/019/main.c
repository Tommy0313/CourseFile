#include <stdio.h>

void reset_dice(int dices[4][6]){
    for(int i=0;i<4;i++){
        for(int j=1;j<=6;j++){
            dices[i][j-1] = j;
        }
    }
}

void dice_copy_dice(int dice[6], int temp_dice[6]){
    for(int i=0;i<6;i++){
        dice[i] = temp_dice[i];
    }
}

void operate_dice(int dice[6],int operate){
    int temp_dice[6];
    switch(operate){
        case 1:
            temp_dice[2] = dice[0];
            temp_dice[1] = dice[1];
            temp_dice[5] = dice[2];
            temp_dice[0] = dice[3];
            temp_dice[4] = dice[4];
            temp_dice[3] = dice[5];

            break;
        case 2:
            temp_dice[3] = dice[0];
            temp_dice[1] = dice[1];
            temp_dice[0] = dice[2];
            temp_dice[5] = dice[3];
            temp_dice[4] = dice[4];
            temp_dice[2] = dice[5];

            break;
        case 3:
            temp_dice[1] = dice[0];
            temp_dice[5] = dice[1];
            temp_dice[2] = dice[2];
            temp_dice[3] = dice[3];
            temp_dice[0] = dice[4];
            temp_dice[4] = dice[5];

            break;
        case 4:
            temp_dice[4] = dice[0];
            temp_dice[0] = dice[1];
            temp_dice[2] = dice[2];
            temp_dice[3] = dice[3];
            temp_dice[5] = dice[4];
            temp_dice[1] = dice[5];
            break;
    }
    dice_copy_dice(dice,temp_dice);
}

int main(){
    int dices[4][6];
    int dice_number[6] = {0};
    reset_dice(dices);

    int N,operate;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&operate);
            operate_dice(dices[j],operate);
        }
    }

    for(int i = 0;i<4;i++){
        dice_number[dices[i][0]-1] ++;
    }

    int four_same = 0;
    int two_same = 0;
    int two_two_same = 0;
    int only_two_same = 0;
    int bigest_number = 0;
    int only_two_sum = 0;

    for(int i=0;i<6;i++){
        if(dice_number[i] == 4) {
            four_same = 1;
        }
        else if(dice_number[i] == 2) {
            two_same += 1;
            bigest_number = i+1;
        }
        else if(dice_number[i] == 1){
            only_two_sum += i+1;
        }
    }

    if(four_same == 1){
        printf("18");
    }
    else if(two_same == 2){
        printf("%d",2*bigest_number);
    }
    else if(two_same == 1){
        printf("%d",only_two_sum);
    }
    else{
        printf("0");
    }

}
