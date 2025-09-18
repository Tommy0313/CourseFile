#include <stdio.h>

int sort_sequence(int A[100],int N){
    int number = 0;
    int bigger_number = -1;
    int last_bigger_number = 9999999;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(A[i]>A[j]) number++;
        }
    }
    return number;

}

int main(){
    int N;
    int A[100];
    int sorted_A_number;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    sorted_A_number = sort_sequence(A,N);
    printf("%d",sorted_A_number);

}
