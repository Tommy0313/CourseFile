#include <stdio.h>
#include <stdlib.h>

#define GATEVALUE(TYPE) int(*GateValue)(struct TYPE*)
typedef struct _Gate {
int input1;
int input2;
GATEVALUE(Gate);
}Gate;
int GateORValue(Gate *gate) {
    return gate->input1 || gate->input2;
}
int GateANDValue(Gate *gate) {
    return gate->input1 && gate->input2;
}
int GateNOTValue(Gate *gate) {
    return !gate->input1;
}
int GateBUFFERValue(Gate *gate) {
    return gate->input1;
}
void CreateGate(Gate *obj, char type, int input1, int input2) {
    obj->input1 = input1;
    obj->input2 = input2;
    switch(type){
        case 'B':
            obj->GateValue=GateBUFFERValue;
            break;
        case 'N':
            obj->GateValue=GateNOTValue;
            break;
        case 'A':
            obj->GateValue=GateANDValue;
            break;
        case 'O':
            obj->GateValue=GateORValue;
            break;
    }
}

void main(){
    int X1,X2,X3;
    Gate P_Gate,Q_Gate,R_Gate;
    char P,Q,R;
    scanf("%d %d %d",&X1,&X2,&X3);
    getchar();
    scanf("%c %c %c",&P,&Q,&R);
    getchar();
    CreateGate(&P_Gate,P,X1,X1);
    CreateGate(&Q_Gate,Q,P_Gate.GateValue(&P_Gate),X2);
    CreateGate(&R_Gate,R,Q_Gate.GateValue(&Q_Gate),X3);
    printf("%d %d %d",P_Gate.GateValue(&P_Gate),Q_Gate.GateValue(&Q_Gate),R_Gate.GateValue(&R_Gate));
}

