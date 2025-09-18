#include <stdio.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
int getMinIndex(int d[], int left, int right, int *select_compare_number) {
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++) {
        (*select_compare_number) ++;
        if (d[i]<d[minIndex]) minIndex=i;
    }
    return minIndex;
}
void selectSort(int d[], int n, int *select_move_number, int *select_compare_number) {
    int i=0, index=0;
    for (i=0; i<n; i++) {
        index = getMinIndex(d, i, n, select_compare_number);
        if(i != index) (*select_move_number) += 3;
        SWAP(d[i], d[index]);
    }
}

void insertionSort(int a[], int n, int *insertion_move_number, int *insertion_compare_number) {
    int target=0, i=0, j=0;
    for (i=1; i<n; i++) {
        (*insertion_move_number) ++;
        target = a[i];
        for (j=i; (j>0) &&(a[j-1]>target) ; j--) {
            *insertion_compare_number += 2;
            (*insertion_move_number) ++;
            a[j] = a[j-1];
        }
        if(!(j>0)){
            (*insertion_compare_number) ++;
        }
        else{
            *insertion_compare_number += 2;
        }
        (*insertion_move_number) ++;
        a[j] = target;
    }
}


int main(){
    int N;
    int select_move_number=0,select_compare_number=0;
    int insertion_move_number=0,insertion_compare_number=0;
    scanf("%d",&N);
    getchar();
    int array1[N],array2[N];
    for(int i=0;i<N;i++){
        scanf("%d",&array1[i]);
        array2[i] = array1[i];
    }

    selectSort(array1,N,&select_move_number,&select_compare_number);
    insertionSort(array2,N,&insertion_move_number,&insertion_compare_number);

    printf("%d %d\n",select_compare_number,select_move_number);
    printf("%d %d\n",insertion_compare_number,insertion_move_number);
}
