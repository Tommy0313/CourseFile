#include <stdio.h>
#define START 0
#define IH 1 //integer head
#define IB 2 //integer body
#define ID 3 //integer defined
#define FI 4 //floating integer part
#define FP 5 //floating point
#define FF 6 //floating decimal
#define FD 7 //floating defined
#define STRING 8
#define VARIABLE 9
#define SORV 10
#define NEG 11
#define STRINGWAIT 12
#define FINEG 13

int getState(int state, char key) { //篈锣传瓜
    if (state==START && key=='0') return FI;
    else if (state==START && key>='1' && key<='9') return IH;
    else if (state==START && key=='-') return NEG;
    else if (state==START && 'A'<=key && key<='z') return SORV;
    else if (state==START && key == '_') return SORV;
    else if (state==NEG && key=='0') return FINEG;
    else if (state==NEG && key>='1' && key<='9') return IH;
    else if (state==FI && key=='.') return FP;
    else if (state==FI && key=='\n') return ID;
    else if (state==FINEG && key=='.') return FP;
    else if (state==FINEG && key=='\n') return STRING;
    else if (state==IH && key=='.') return FP;
    else if (state==IB && key=='.') return FP;
    else if (state==FP && key>='0' && key<='9') return FF;
    else if (state==FF && key>='0' && key<='9') return FF;
    else if (state==FF && key=='\n') return FD;
    else if (state==IH && key>='0' && key<='9') return IB;
    else if (state==IB && key>='0' && key<='9') return IB;
    else if (state==IB && key=='\n') return ID;
    else if (state==SORV && key>='0' && key<='9') return SORV;
    else if (state==SORV && 'A'<=key && key<='z') return SORV;
    else if (state==SORV && key == '_') return SORV;
    else if (state==SORV && key=='\n') return VARIABLE;
    else if (state==STRINGWAIT && key=='\n') return STRING;
    else if (key=='\n') return STRING;
    else return STRINGWAIT;
}

int inputString(){
    char key;
    int state=START;
    int i=0;
    while (1) {
        key = getchar();
        state = getState(state, key);
        //printf("%d\n",state);
        if (state==STRING) { //獶俱计疊翴计
            printf("string");
            break;
        }
        else if (state==FD) { //疊翴计
            printf("float");
            break;
        }
        else if (state==ID) {//俱计
            printf("integer");
            break;
        }
        else if (state==VARIABLE) {//俱计
            if(i>10){
                printf("string");
                break;
            }
            else{
                printf("variable");
                break;
            }
        }
        i++;
    }
}

int main(){
    int number;
    scanf("%d",&number);
    getchar();
    for(int i=0;i<number;i++){
        inputString();
        printf("\n");
    }
}
