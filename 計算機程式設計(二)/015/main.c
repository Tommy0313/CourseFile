#include <stdio.h>
#include <math.h>


int is_continuous_subsequence(int m, int subsequence[m]) {
    int number[10] = {0};
    for(int i = 0;i<m;i++){
        number[subsequence[i]] ++;
        if(number[subsequence[i]] > 1){
            return 0;
        }
    }
    return 1;
}

int array_to_number(int m,int array[m]){
    int pow_number = m, return_number = 0;
    for(int i=0;i<m;i++){
        pow_number--;
        return_number += array[i]*pow(10,pow_number);
    }
    return return_number;
}

// 将一个子序列按照升序排序
int sort_sequence(int m,int total_sequences,int sequence[20],int sorted_sequence[20][m]) {
    int total_subsequences = 0;
    int small_number,last_small_number = 0;
    int index,last_index = -1;
    while(1){
        small_number = 99999999999;
        for(int i=0;i<total_sequences-m+1;i++){
            if(array_to_number(m,sequence+i)<small_number && array_to_number(m,sequence+i)>last_small_number && is_continuous_subsequence(m,sequence+i)){
                small_number = array_to_number(m,sequence+i);
                index = i;
            }
        }
        if(last_index == index){
            break;
        }
        else{
            for(int i = 0;i<m;i++){
                sorted_sequence[total_subsequences][i] = sequence[index+i];
            }
            total_subsequences ++;
            last_small_number = small_number;
            last_index = index;
        }
    }

    return total_subsequences;
}

int main() {
    int m;
    int sequence[20];
    int i, j, k, temp;
    int total_sequences = 0;

    scanf("%d", &m);

    for (i = 0; i <= 20; i++) {
        scanf("%d", &temp);
        if (temp == -1) {
            break;
        }
        total_sequences ++;
        sequence[i] = temp;
    }
    int sorted_subsequence[20][m];

    int total_subsequences = 0;
    total_subsequences = sort_sequence(m,total_sequences,sequence,sorted_subsequence);

    int total_number = 0;
    for(int i=0;i<total_sequences-m+1;i++){
        if(is_continuous_subsequence(m,sequence+i)){
            total_number ++;
        }
    }

    // 输出结果
    printf("%d\n", total_number);
    for (i = 0; i < total_subsequences; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", sorted_subsequence[i][j]);
        }
        printf("\n");
    }

    return 0;
}
