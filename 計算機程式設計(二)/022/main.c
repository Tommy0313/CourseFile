#include <stdio.h>
#include <string.h>

int k_compare(char str[51],int k){
    int str_len = strlen(str);
    int max_number = 0;
    int control,continue_words,times = 0;
    if(str[0] <= 'Z'){
        control = 1;
    }
    else{
        control = 0;
    }
    for(int i=0;i<str_len;i=i+k){
        continue_words = 1;
        if(control==1){
            for(int j=0;j<k;j++){
                if('a' <= str[j+i] && 'z' >= str[j+i]){
                    continue_words = 0;
                }
            }
            control = 0;
        }
        else{
            for(int j=0;j<k;j++){
                if('A' <= str[j+i] && 'Z' >= str[j+i]){
                    continue_words = 0;
                }
            }
            control = 1;
        }
        if(continue_words == 0){
            break;
        }
        times++;
    }
    if(times == 1){
        max_number = 0;
    }
    else{
        max_number = times * k;
    }

    return max_number;
}

int compare(char str[51],int k){
    int str_len = strlen(str);
    int max_number = 0;
    int temp_number = 0;

    for(int i=0;i<str_len;i++){
        temp_number = k_compare(&str[i],k);
        if(temp_number > max_number){
            max_number = temp_number;
        }
    }

    return max_number;
}

int main(){
    int N,k;
    char str[51];

    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%s %d",str,&k);
        getchar();
        printf("%d\n",compare(str,k));
    }
}
