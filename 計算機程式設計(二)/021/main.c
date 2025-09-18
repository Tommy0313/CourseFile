#include <stdio.h>
#include <string.h>

int compare1(char S1[101],char S2[101]){
    int result = 1;
    int S1_number = 0,S2_number = 0;
    char S1_words[10][11],S2_words[10][11];
    char *pch;
    char *delim = " ";

    pch = strtok(S1,delim);
    strcpy(S1_words[S1_number],pch);
    S1_number++;
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch!=NULL){
            strcpy(S1_words[S1_number],pch);
            S1_number++;
        }
    }

    pch = strtok(S2,delim);
    strcpy(S2_words[S2_number],pch);
    S2_number++;
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch!=NULL){
            strcpy(S2_words[S2_number],pch);
            S2_number++;
        }
    }

    for(int i=0;i<S1_number;i++){
        for(int j=0;j<S2_number;j++){
            if(strcmp(S1_words[i],S2_words[j])==0){
                result = 0;
            }
        }
    }


    return result;
}

int compare2(char sentence[101],char S1[101],char S2[101]){
    int result = 1;
    int all_number = 0;
    char all_words[20][11];
    int S_number = 0;
    char S_words[10][11];
    int S_words_number[20] = {0};
    char *pch;
    char *delim = " ";

    pch = strtok(S1,delim);
    strcpy(all_words[all_number],pch);
    all_number++;
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch!=NULL){
            strcpy(all_words[all_number],pch);
            all_number++;
        }
    }

    pch = strtok(S2,delim);
    strcpy(all_words[all_number],pch);
    all_number++;
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch!=NULL){
            strcpy(all_words[all_number],pch);
            all_number++;
        }
    }

    pch = strtok(sentence,delim);
    strcpy(S_words[S_number],pch);
    S_number++;
    while(pch != NULL){
        pch = strtok(NULL,delim);
        if(pch!=NULL){
            strcpy(S_words[S_number],pch);
            S_number++;
        }
    }

    for(int i=0;i<S_number;i++){
        for(int j=0;j<all_number;j++){
            if(strcmp(S_words[i],all_words[j])==0){
                S_words_number[i] ++;
            }
        }
    }

    for(int i=0;i<S_number;i++){
        if(S_words_number[i] == 0){
            result = 0;
        }
    }


    return result;
}

int main(){
    char sentence[101];
    char temp_sentence[101];
    char compare_string[10][101];
    char temp_compare_string1[101],temp_compare_string2[101];
    int compare_string_number,condition1,condition2;
    int result_number = 0;
    fgets(sentence,101,stdin);
    sentence[strlen(sentence)-1] = '\0';
    scanf("%d",&compare_string_number);
    getchar();
    for(int i=0;i<compare_string_number;i++){
        fgets(compare_string[i],101,stdin);
        compare_string[i][strlen(compare_string[i])-1] = '\0';
    }

    for(int i=0;i<compare_string_number;i++){
        for(int j=i+1;j<compare_string_number;j++){

            strcpy(temp_compare_string1,compare_string[i]);
            strcpy(temp_compare_string2,compare_string[j]);
            condition1 = compare1(temp_compare_string1,temp_compare_string2);

            strcpy(temp_compare_string1,compare_string[i]);
            strcpy(temp_compare_string2,compare_string[j]);
            strcpy(temp_sentence,sentence);
            condition2 = compare2(temp_sentence,temp_compare_string1,temp_compare_string2);

            if(condition1==1 && condition2==1){
                result_number++;
            }
        }
    }

    printf("%d",result_number);

}
