#include <stdio.h>
#include <string.h>

int charToInt(char number){
    return number - 48;
}

void copy_array(char from_array[201],char to_array[201]){
    for(int i=0;i<strlen(from_array)+1;i++){
        to_array[i] = from_array[i];
    }
}

void add_zero_in_array(char array[201],int change){
    int number = strlen(array);
    for(int i = 0;i<change;i++){
        array[number + i] = '0';
    }
    array[number + change] = '\0';
}

void add_negative(char array[201]){
    int number = strlen(array);
    for(int i = number-1;i>=0;i--){
        array[i+1] = array[i];
    }
    array[0] = '-';
    array[number+1] = '\0';
}

void remove_negative(char array[201]){
    int number = strlen(array);
    for(int i = 0;i<=number;i++){
        array[i] = array[i+1];
    }
}

int array_equal(char array1[201], char array2[201]){
    int len = strlen(array1);
    for(int i=0;i<len;i++){
        if(array1[i] != array2[i]){
            return 0;
        }
    }
    return 1;
}

void plus(char first_number[201],char second_number[201],char show_number[201]){
    int max_number;
    int first_number_len = strlen(first_number);
    int second_number_len = strlen(second_number);
    if(first_number_len > second_number_len){
        max_number = first_number_len;
    }
    else{
        max_number = second_number_len;
    }
    max_number++;
    show_number[max_number] = '\0';

    int carry = 0;
    char first, second;
    while(max_number > 0){
        first_number_len --;
        second_number_len --;
        max_number --;
        if(first_number_len < 0){
            first = '0';
        }
        else{
            first = first_number[first_number_len];
        }
        if(second_number_len < 0){
            second = '0';
        }
        else{
            second = second_number[second_number_len];
        }

        if(charToInt(first)+charToInt(second)+carry >= 10){
            show_number[max_number] = charToInt(first)+charToInt(second)+carry-10 + 48;
            carry = 1;
        }
        else{
            show_number[max_number] = charToInt(first)+charToInt(second)+carry + 48;
            carry = 0;
        }
    }
    if(show_number[0] == '0'){
       max_number = strlen(show_number);
       show_number[max_number] = '\0';
       for(int i = 0;i<max_number;i++){
        show_number[i] = show_number[i+1];
       }
    }

    return show_number;
}

void minus(char first_number[201],char second_number[201],char show_number[201]){
    int max_number;
    int first_number_len = strlen(first_number);
    int second_number_len = strlen(second_number);
    int negative = 0;
    char big_number[201];
    char small_number[201];
    int result = 0;

    if(first_number_len == second_number_len){
        result = array_equal(first_number,second_number);
    }
    if(result == 1){
        show_number[0] = '0';
        show_number[1] = '\0';
    }
    else{
        if(first_number_len > second_number_len){
            max_number = first_number_len;
            copy_array(first_number,big_number);
            copy_array(second_number,small_number);
        }
        else{
            max_number = second_number_len;
            if(first_number_len < second_number_len){
                copy_array(second_number,big_number);
                copy_array(first_number,small_number);
                negative = 1;
            }
            else{
                for(int i = 0;i<max_number;i++){
                    if(first_number[i]> second_number[i]){
                        copy_array(first_number,big_number);
                        copy_array(second_number,small_number);
                        break;
                    }
                    else if(first_number[i]<second_number[i]){
                        copy_array(second_number,big_number);
                        copy_array(first_number,small_number);
                        negative = 1;
                        break;
                    }
                }
            }
        }

        int big_number_len = strlen(big_number);
        int small_number_len = strlen(small_number);
        show_number[max_number] = '\0';

        int carry = 0;
        char first, second;
        while(max_number > 0){
            big_number_len --;
            small_number_len --;
            max_number --;

            first = big_number[big_number_len];

            if(small_number_len < 0){
                second = '0';
            }
            else{
                second = small_number[small_number_len];
            }

            if(charToInt(first)-charToInt(second)-carry < 0){
                show_number[max_number] = charToInt(first)-charToInt(second)-carry+10 + 48;
                carry = 1;
            }
            else{
                show_number[max_number] = charToInt(first)-charToInt(second)-carry + 48;
                carry = 0;
            }
        }


        int first_time = 1;
        int change_position = 0;
        for(int i = 0;i<strlen(show_number);i++){
            if(first_number==1&&show_number[i]=='0'){
                first_time = 0;
                change_position++;
            }
            else{
                break;
            }
            if(first_time==0&&show_number[i]=='0'){
                if(i != strlen(show_number)-1){
                    change_position++;
                }
            }
            else{
                break;
            }
        }

        if(change_position !=0){
            max_number = strlen(show_number);
           show_number[max_number+1] = '\0';
           for(int i = 0;i<max_number-change_position;i++){
                show_number[i] = show_number[i+change_position];
           }
           show_number[max_number-change_position] = '\0';
        }

        if(negative == 1){
           max_number = strlen(show_number);
           show_number[max_number+1] = '\0';
           for(int i = max_number-1;i>=0;i--){
                show_number[i+1] = show_number[i];
           }
           show_number[0] = '-';
        }
    }

    return show_number;
}

void multiply(char first_number[201],char second_number[201],char show_number[201]){
    char multiply_number[201];
    char total_multiply_number[201];
    char total_number[201];
    int first_number_len = strlen(first_number);
    int second_number_len = strlen(second_number);

    int j = 0;
    for(int i=second_number_len-1;i>=0;i--){
        if(second_number[i] != '0'){
            copy_array(first_number,multiply_number);
            copy_array(first_number,total_multiply_number);
            for(int k=0;k<charToInt(second_number[i])-1;k++){
                plus(multiply_number,first_number,total_multiply_number);
                copy_array(total_multiply_number,multiply_number);
            }
            add_zero_in_array(total_multiply_number,j);

            if(j==0){
                copy_array(total_multiply_number,total_number);
            }
            else{
                plus(total_number,total_multiply_number,show_number);
                copy_array(show_number,total_number);
            }
        }
        j++;
    }
}

int main(){
    char first_number[101], second_number[101];
    char show_plus_number[201];
    char show_minus_number[201];
    char show_multiply_number[201];
    char plus_first_number[201],plus_second_number[201];
    char minus_first_number[201],minus_second_number[201];
    char multiply_first_number[201],multiply_second_number[201];

    scanf("%s",first_number);
    getchar();
    scanf("%s",second_number);
    getchar();

    copy_array(first_number,plus_first_number);
    copy_array(second_number,plus_second_number);
    copy_array(first_number,minus_first_number);
    copy_array(second_number,minus_second_number);
    copy_array(first_number,multiply_first_number);
    copy_array(second_number,multiply_second_number);

    if(first_number[0]!='-'&& second_number[0]!='-'){
        plus(plus_first_number,plus_second_number, show_plus_number);
    }
    else if(first_number[0]!='-'&& second_number[0]=='-'){
        remove_negative(plus_second_number);
        minus(plus_first_number,plus_second_number,show_plus_number);
    }
    else if(first_number[0]=='-'&& second_number[0]!='-'){
        remove_negative(plus_first_number);
        minus(plus_second_number,plus_first_number,show_plus_number);
    }
    else{
        remove_negative(plus_first_number);
        remove_negative(plus_second_number);
        plus(plus_first_number,plus_second_number, show_plus_number);
        add_negative(show_plus_number);
    }

    printf("%s\n",show_plus_number);

    if(first_number[0]!='-'&& second_number[0]!='-'){
        minus(minus_first_number,minus_second_number, show_minus_number);
    }
    else if(first_number[0]!='-'&& second_number[0]=='-'){
        remove_negative(minus_second_number);
        plus(minus_first_number,minus_second_number,show_minus_number);
    }
    else if(first_number[0]=='-'&& second_number[0]!='-'){
        remove_negative(minus_first_number);
        plus(minus_first_number,minus_second_number, show_minus_number);
        add_negative(show_minus_number);
    }
    else{
        remove_negative(minus_first_number);
        remove_negative(minus_second_number);
        minus(minus_second_number,minus_first_number, show_minus_number);
    }

    printf("%s\n",show_minus_number);

    if(first_number[0]!='-'&& second_number[0]!='-'){
        multiply(multiply_first_number,multiply_second_number, show_multiply_number);
    }
    else if(first_number[0]!='-'&& second_number[0]=='-'){
        remove_negative(multiply_second_number);
        multiply(multiply_first_number,multiply_second_number,show_multiply_number);
        add_negative(show_multiply_number);
    }
    else if(first_number[0]=='-'&& second_number[0]!='-'){
        remove_negative(multiply_first_number);
        multiply(multiply_first_number,multiply_second_number, show_multiply_number);
        add_negative(show_multiply_number);
    }
    else{
        remove_negative(multiply_first_number);
        remove_negative(multiply_second_number);
        multiply(multiply_first_number,multiply_second_number, show_multiply_number);
    }

    printf("%s\n",show_multiply_number);

}
