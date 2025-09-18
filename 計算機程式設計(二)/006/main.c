#include<stdio.h>

int mode1(int M){
    for(int i=0;i<M;i++){
        for(int j=M-i-1;j>0;j--){
            printf("#");
        }

        for(int j=i;j>0;j--){
            printf("*");
            if(i%3==1){
                printf("A");
            }
            else if(i%3==2){
                printf("B");
            }
            else{
                printf("C");
            }
        }

        printf("*");
        for(int j=M-i-1;j>0;j--){
            printf("#");
        }
        printf("\n");
    }
}

int mode2(int M){
    for(int i=1;i<M+1;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }

        for(int j=M-i+1;j>0;j--){
            printf("*");
            printf("*");
        }

        for(int j=i;j>0;j--){
            printf("%d",j);
        }
        printf("\n");
    }
}


int main(){
    int N,M;
    scanf("%d",&N);
    getchar();
    scanf("%d",&M);
    getchar();
    if((1<=N && N<=2) && (2<=M && M<=9)){
        if(N==1){
            mode1(M);
        }
        else if(N==2){
            mode2(M);
        }
    }
    else{
        printf("error");
    }
}
