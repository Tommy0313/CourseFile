#include<stdio.h>
#include<math.h>

int G(int n, int k){
    if(n==1){
        printf("%d",k);
    }
    else if(k<pow(2,n-1)){
        printf("%d",0);
        G(n-1,k);
    }
    else{
        printf("%d",1);
        G(n-1,pow(2,n)-1-k);
    }
}

int main(){
    int n, k;
    while(1){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        scanf(" %d",&k);
        getchar();
        G(n,k);
        printf("\n");
    }
}
