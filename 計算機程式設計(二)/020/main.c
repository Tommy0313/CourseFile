#include <stdio.h>
#include <string.h>
int same(char sentence[2000],char P[21]){
    int result = 1;
    int P_len = strlen(P);
    int i = 0;
    while(sentence[i] != ' '){
        if(P[i] != sentence[i]){
            result = 0;
        }
        i++;
    }
    return result;
}


void one(char sentence[2000],char P[21],char Q[21]){
    char *pch;
    char *delim = " ";

    pch = strtok(sentence,delim);
    if(strcmp(pch,P)==0){
        printf("%s",Q);
    }
    else{
        printf("%s",pch);
    }
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch != NULL){
            if(strcmp(pch,P)==0){
                printf(" %s",Q);
            }
            else{
                printf(" %s",pch);
            }

        }
    }

    printf("\n");

}

void two(char sentence[2000],char P[21],char Q[21]){
    char *pch;
    char *delim = " ";

    pch = strtok(sentence,delim);
    if(strcmp(pch,P)==0){
        printf("%s %s",Q,pch);
    }
    else{
        printf("%s",pch);
    }
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch != NULL){
            if(strcmp(pch,P)==0){
                printf(" %s %s",Q,pch);
            }
            else{
                printf(" %s",pch);
            }

        }
    }

    printf("\n");
}

void three(char sentence[2000],char P[21],char Q[21]){
    char *pch;
    char *delim = " ";

    pch = strtok(sentence,delim);
    if(strcmp(pch,P)==0){

    }
    else{
        printf("%s",pch);
    }
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch != NULL){
            if(strcmp(pch,P)==0){
            }
            else{
                printf(" %s",pch);
            }

        }
    }

    printf("\n");

}

void sort1(int number,int compare_temp_number[50],char words[50][21]){
    int index;
    int temp;
    for(int i=0;i<number-1;i++){
        index = i;
        for(int j=i;j<number;j++){
            if(strcmp(words[compare_temp_number[j]],words[compare_temp_number[index]]) < 0){
                index = j;
            }
        }
        temp = compare_temp_number[i];
        compare_temp_number[i] = compare_temp_number[index];
        compare_temp_number[index] = temp;
    }

}

void copy(char *dest, char *src){

    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = *src;
}

void four(char sentence[2000]){
    char *pch;
    char *delim = " ";
    char words[50][21];
    int count_words_number[50] = {0};
    int word_number = 1;
    int not_find = 1;

    pch = strtok(sentence,delim);
    strcpy(words[0],pch);
    count_words_number[0] = 1;
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch != NULL){
            for(int i=0;i<word_number;i++){
                if(strcmp(words[i],pch) == 0){
                    copy(words[i],pch);
                    words[i][strlen(pch)] = '\0';
                    count_words_number[i] = count_words_number[i] + 1;
                    not_find = 0;
                    break;
                }
                not_find = 1;
            }
            if(not_find == 1){
                copy(words[word_number],pch);
                words[word_number][strlen(pch)] = '\0';
                count_words_number[word_number] = 1;
                word_number++;
            }
        }
    }

    static int compare_temp_number[50] = {0};
    int number = 0;
    for(int i=50;i>0;i--){
        number = 0;
        for(int j=0;j<word_number;j++){
            if(count_words_number[j] == i){
                compare_temp_number[number] = j;
                number++;
            }
        }

        sort1(number,compare_temp_number,words);

        if(number != 0){
            for(int j=0;j<number;j++){
                printf("%s %d\n",words[compare_temp_number[j]],count_words_number[compare_temp_number[j]]);
            }
        }
    }

}


int main(){
    char sentence[2000];
    char temp_sentence[2000];
    char P[21],Q[21];
    fgets(sentence,2000,stdin);
    scanf("%s",P);
    scanf("%s",Q);
    sentence[strlen(sentence)-1] = '\0';

    strcpy(temp_sentence,sentence);
    one(temp_sentence,P,Q);
    strcpy(temp_sentence,sentence);
    two(temp_sentence,P,Q);
    strcpy(temp_sentence,sentence);
    three(temp_sentence,P,Q);
    four(sentence);
}
