#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s * right, * left;
} tree_t;
typedef tree_t * btree;

btree create(char data){
    btree newNode = (btree)malloc(sizeof(tree_t));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(char I[20],int Istart,int Iend,char data){
    for(int i=Istart;i<=Iend;i++){
        if(I[i] == data){
            return i;
        }
    }
}

btree buildTreePI(char P[20],char I[20],int Istart,int Iend,int *Pindex){
    if(Istart > Iend){
        return NULL;
    }

    btree Node = create(P[*(Pindex)]);
    (*Pindex)++;

    if(Istart == Iend){
        return Node;
    }

    int Iindex = search(I,Istart,Iend,Node->data);

    Node->left = buildTreePI(P,I,Istart,Iindex-1,Pindex);
    Node->right = buildTreePI(P,I,Iindex+1,Iend,Pindex);

    return Node;
}

btree buildTreeIO(char O[20],char I[20],int Istart, int Iend, int *Oindex){
    if(Istart>Iend){
        return NULL;
    }

    btree Node = create(O[*Oindex]);
    (*Oindex)--;

    if(Istart == Iend){
        return Node;
    }

    int Iindex = search(I,Istart,Iend,Node->data);

    Node->right = buildTreeIO(O,I,Iindex+1,Iend,Oindex);
    Node->left = buildTreeIO(O,I,Istart,Iindex-1,Oindex);

    return Node;

}

void print(btree root){
    int root_index = 0;
    int list_index = 0;
    btree list_root[20];

    list_root[root_index++] = root;
    while(list_index < root_index){
        btree temp = list_root[list_index++];
        printf("%c",temp->data);

        if(temp->left!= NULL){
            list_root[root_index++] = temp->left;
        }
        if(temp->right!= NULL){
            list_root[root_index++] = temp->right;
        }

    }

}

int main(){
    int N;
    char type1,type2;
    char tree1[20];
    char tree2[20];
    scanf("%d",&N);
    getchar();
    scanf("%c",&type1);
    getchar();
    scanf("%s",tree1);
    getchar();
    scanf("%c",&type2);
    getchar();
    scanf("%s",tree2);
    getchar();
    int length = N;
    btree root;
    if(type1 == 'P' && type2 == 'I'){
        int Pindex = 0;
        root = buildTreePI(tree1,tree2,0,length-1,&Pindex);
    }
    else if(type1 == 'I' && type2 == 'O'){
        int Oindex = length-1;
        root = buildTreeIO(tree2,tree1,0,length-1,&Oindex);
    }

    print(root);

}
