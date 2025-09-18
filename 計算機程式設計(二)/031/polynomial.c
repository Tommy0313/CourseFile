#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node_s {
int pow;
int number;
struct node_s * next;
}node_t;
typedef node_t * nodep_t;

nodep_t create(int pow,int number){
    nodep_t newNode;
    newNode= (nodep_t)malloc(sizeof(node_t));
    newNode->pow = pow;
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

nodep_t createPolynomial(int N[100],int j){
    nodep_t top = NULL,temp,current;
    int i=0;
    for(int k=j;k>=0;k--){
        temp = create(k,N[i]);
        if(top == NULL){
            top = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = current->next;
        }
        i++;
    }
    return top;
}

int max(int i,int j){
    if(i>j){
        return i;
    }
    else{
        return j;
    }
}

void add(nodep_t one,nodep_t two){
    int i = max(one->pow,two->pow);
    nodep_t result = NULL,temp,current;
    int now_number = 0;
    for(;i>=0;i--){
        now_number = 0;
        if(one->pow == i){
            now_number = now_number + one->number;
            one = one->next;
        }
        if(two->pow == i){
            now_number = now_number + two->number;
            two = two->next;
        }
        temp = create(i,now_number);
        if(result == NULL){
            result = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = current->next;
        }
    }
    if(find_number_nonzero(result) == 0){
        printf("0\n");
    }
    else{
        printResult(result);
    }

}


void minus(nodep_t one,nodep_t two){
    int i = max(one->pow,two->pow);
    nodep_t result = NULL,temp,current;
    int now_number = 0;
    for(;i>=0;i--){
        now_number = 0;
        if(one->pow == i){
            now_number = now_number + one->number;
            one = one->next;
        }
        if(two->pow == i){
            now_number = now_number - two->number;
            two = two->next;
        }
        temp = create(i,now_number);
        if(result == NULL){
            result = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = current->next;
        }
    }
    if(find_number_nonzero(result) == 0){
        printf("0\n");
    }
    else{
        printResult(result);
    }

}

void multiply(nodep_t one,nodep_t two){
    int pow = one->pow+two->pow;
    int N[100] = {0};
    nodep_t result = createPolynomial(N,pow);
    nodep_t current_two;
    int number;
    while(one != NULL){
        current_two = two;
        while(current_two != NULL){
            pow = one->pow + current_two->pow;
            number = one->number * current_two->number;
            find_same_pow(result,pow,number);
            current_two = current_two->next;
        }

        one = one->next;
    }
    if(find_number_nonzero(result) == 0){
        printf("0\n");
    }
    else{
        printResult(result);
    }
}

void find_same_pow(nodep_t current,int pow,int number){
    while(current != NULL){
        if(current->pow==pow){
            current->number = current->number + number;
            break;
        }
        current = current->next;
    }
}

int find_number_nonzero(nodep_t current){
    while(current != NULL){
        if(current->number != 0){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print(int pow,int number,int firstTime){
    if(firstTime == 1){
        if(number < 0){
            printf("-");
        }
        if(pow == 0){
            printf("%d",abs(number));
        }
        else if(pow == 1){
            if(abs(number) == 1){
                printf("x");
            }
            else{
                printf("%dx",abs(number));
            }
        }
        else if(pow >= 2){
            if(abs(number) == 1){
                printf("x^%d",pow);
            }
            else{
                printf("%dx^%d",abs(number),pow);
            }
        }
    }
    else{
        if(number < 0){
            printf("-");
        }
        else if(number > 0){
            printf("+");
        }
        if(number != 0){
            if(pow == 0){
                printf("%d",abs(number));
            }
            else if(pow == 1){
                if(abs(number) == 1){
                    printf("x");
                }
                else{
                    printf("%dx",abs(number));
                }
            }
            else if(pow >= 2){
                if(abs(number) == 1){
                    printf("x^%d",pow);
                }
                else{
                    printf("%dx^%d",abs(number),pow);
                }
            }
        }
    }
}


void printResult(nodep_t result){
    print(result->pow,result->number,1);
    result = result->next;
    while(result != NULL){
        print(result->pow,result->number,0);
        result = result->next;
    }
    printf("\n");
}

int main(){
    int N[2][100];
    char keyword;
    nodep_t one = NULL;
    nodep_t two = NULL;
    for(int i = 0;i<2;i++){
        int j=0;
        while(1){
            scanf("%d",&N[i][j]);
            keyword = getchar();
            if(keyword == '\n'){
                break;
            }
            j++;
        }
        if(i == 0){
            one = createPolynomial(N[i],j);
        }
        else{
            two = createPolynomial(N[i],j);
        }
    }
    add(one,two);
    minus(one,two);
    multiply(one,two);


}
