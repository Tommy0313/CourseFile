#include <stdio.h>
#include <string.h>

void initialize_grid(int N,int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j] = 0;
        }
    }
}

void pop(char expression[101]){
    for(int i=0;i<strlen(expression);i++){
        expression[i] = expression[i+1];
    }
}

void fill_black_grid(int N,int top,int bottom,int left,int right,int grid[N][N]){
    for(int i = top;i<bottom+1;i++){
        for(int j = left;j<right+1;j++){
            grid[i][j] = 1;
        }
    }
}


int write_black_grid(int N,char expression[101],int top,int bottom,int left,int right,int grid[N][N]){
    if(expression[0] == '2'){
        pop(expression);
        write_black_grid(N,expression,top,(bottom+top)/2,left,(right+left)/2,grid);
        write_black_grid(N,expression,top,(bottom+top)/2,(right+left)/2+1,right,grid);
        write_black_grid(N,expression,(bottom+top)/2+1,bottom,left,(right+left)/2,grid);
        write_black_grid(N,expression,(bottom+top)/2+1,bottom,(right+left)/2+1,right,grid);
    }
    else if(expression[0] == '1'){
        pop(expression);
        fill_black_grid(N,top,bottom,left,right,grid);
    }
    else{
        pop(expression);
    }
}

void print_black_grid(int N,int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 1){
                printf("%d,%d\n",i,j);
            }
        }
    }
}

int main(){
    char expression[101];
    int N;
    scanf("%s",&expression);
    getchar();
    scanf("%d",&N);
    getchar();
    if(expression[0] == '0' && expression[1] == '\0'){
        printf("all white");
    }
    else{
        int grid[N][N];
        initialize_grid(N,grid);
        write_black_grid(N,expression,0,N-1,0,N-1,grid);
        print_black_grid(N,grid);
    }
}
