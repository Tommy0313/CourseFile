#include <stdio.h>
#include<math.h>
#include <string.h>

int gcd(int m,int n){
    if(n==0){
        return m;
    }
    else{
        return gcd(n, m%n);
    }
}


int main(){
    int first_input_number, second_input_number, third_input_number, first_child_number, first_mother_number, second_child_number, second_mother_number;
    int output_child_number, output_mother_number, output_number;
    int divide_number;
    char first_input_symbol, input_count_symbol, yes_or_no;
    while(1){
        scanf("%d%c%d/%d)",&first_input_number,&first_input_symbol,&second_input_number,&third_input_number);
        getchar();
        if(first_input_symbol == '('){
            if(first_input_number<0){
                second_input_number = -second_input_number;
            }
            first_child_number = first_input_number*third_input_number + second_input_number;
            first_mother_number= third_input_number;
        }
        else{
            first_child_number = first_input_number;
            first_mother_number = second_input_number;
        }

        scanf("%c",&input_count_symbol);
        getchar();

        scanf("%d%c%d/%d)",&first_input_number,&first_input_symbol,&second_input_number,&third_input_number);
        getchar();
        if(first_input_symbol == '('){
            if(first_input_number<0){
                second_input_number = -second_input_number;
            }
            second_child_number = first_input_number*third_input_number + second_input_number;
            second_mother_number= third_input_number;
        }
        else{
            second_child_number = first_input_number;
            second_mother_number = second_input_number;
        }

        switch(input_count_symbol){
            case '+':
                output_child_number = first_child_number*second_mother_number + second_child_number*first_mother_number;
                output_mother_number = first_mother_number*second_mother_number;
                break;
            case '-':
                output_child_number = first_child_number*second_mother_number - second_child_number*first_mother_number;
                output_mother_number = first_mother_number*second_mother_number;
                break;
            case'*':
                output_child_number = first_child_number*second_child_number;
                output_mother_number = first_mother_number*second_mother_number;
                break;
            case '/':
                if(second_child_number <0){
                    second_child_number = -second_child_number;
                    second_mother_number = -second_mother_number;
                }
                output_child_number = first_child_number*second_mother_number;
                output_mother_number = first_mother_number*second_child_number;
        }
        if(output_mother_number == 0){
            printf("error\n");
        }
        else{
            output_number = output_child_number / output_mother_number;
            output_child_number = output_child_number % output_mother_number;
            if(output_number !=0 && output_child_number < 0){
                output_child_number = -output_child_number;
            }
            divide_number = gcd(output_child_number, output_mother_number);
            if(divide_number != 0){
                if(divide_number < 0) divide_number = -divide_number;
                output_child_number = output_child_number / divide_number;
                output_mother_number = output_mother_number / divide_number;
            }

            if(output_number == 0 && output_child_number == 0){
                printf("0\n");
            }
            else if(output_number == 0){
                printf("%d/%d\n",output_child_number,output_mother_number);
            }
            else if(output_child_number == 0){
                printf("%d\n",output_number);
            }
            else{
                printf("%d(%d/%d)\n",output_number,output_child_number,output_mother_number);
            }
        }
        scanf("%c",&yes_or_no);
        getchar();
        if(yes_or_no == 'n'){
            break;
        }
    }
}
