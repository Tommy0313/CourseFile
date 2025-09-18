#include <stdio.h>
#include<math.h>
#include <string.h>

int codeToNumber(char word){
    if(48 <= word && word <=57){
        return word - 48;
    }
    else if(65 <=word && word <= 90){
        return word - 55;
    }
}

char numberToCode(int number){
    if(0 <= number && number <= 9){
        return number + 48;
    }
    else if(10 <= number && number <= 35){
        return number + 55;
    }
}

int inputToDecimal(char code[11],int inputCode){
    int decimal = 0;
    for(int i=strlen(code)-1;i>=0;i--){
        decimal += codeToNumber(code[i])*pow(inputCode,strlen(code)-i-1);
    }
    return decimal;
}

void DecimalToOutput(int outputCode,int decimal){
    char output[100];
    int i = 0;
    if(decimal == 0){
        printf("0");
    }
    else{
        while(decimal!=0){
            output[i] = numberToCode(decimal % outputCode);
            decimal /= outputCode;
            i++;
        }
        for(i=i-1;i>=0;i--){
            printf("%c",output[i]);
        }
    }
}



int main(){
    int inputCode,outputCode,decimal;
    char code[11];
    scanf("%d",&inputCode);
    getchar();
    scanf("%s",code);
    getchar();
    decimal = inputToDecimal(code,inputCode);
    scanf("%d",&outputCode);
    getchar();
    DecimalToOutput(outputCode, decimal);

}
