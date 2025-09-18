#include <stdio.h>
#include<math.h>
#include <string.h>

int R(int n){
    if(n<=1){
        return 0;
    }
    else if(n%2==0){
        return 1 + R(n/2);
    }
    else{
        return 1 + R((n+1)/2);
    }
}

int BinaryToDecimal(char binary[],int pow_number){
    int binary_number = strlen(binary);
    if(pow_number == binary_number){
        return binary[pow_number];
    }
    else{
        if(binary[pow_number] =='0'){
            return BinaryToDecimal(binary, pow_number+1);
        }
        else {
            return pow(2,binary_number-pow_number-1) + BinaryToDecimal(binary, pow_number+1);
        }
    }
}

int DecimalToBinary(int decimal, int pow_number, char output[]){
    if(decimal<=1){
        if(decimal==1){
            output[14-pow_number-1] = '1';
        }
        else{
            output[14-pow_number-1] = '0';
        }
    }
    else if(decimal%2!=0){
        output[14-pow_number-1] = '1';
        DecimalToBinary((decimal-1)/2,pow_number+1,output);
    }
    else{
        output[14-pow_number-1] = '0';
        DecimalToBinary(decimal/2,pow_number+1,output);
    }
}

int main(){
    int decimal, k, int_output=0;
    while(1){
        int_output=0;
        char binary[11], output[]="00000000000000";
        scanf("%s",binary);
        getchar();
        decimal = BinaryToDecimal(binary, 0);
        for(int i=0;i<=decimal;i++){
            int_output += R(i);
        }
        DecimalToBinary(int_output,0,output);
        printf("%s\n",output);
        scanf("%d",&k);
        getchar();
        if(k == -1){
            break;
        }
    }
}
