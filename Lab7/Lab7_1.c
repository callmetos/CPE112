//Channathat Ueanapaphon 66070503413

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct AVL{
    int val;
    struct AVL *LEFT;
    struct AVL *RIGHT;
    int hight;
}AVLT;

int getinsert(int **in,char *command){
    int val;
    int size = 0;
    int *arr = NULL;
    while(scanf("%d",&val)== 1){
        size++;
        arr=realloc(arr, size * sizeof(int));
        arr[size-1]=val;

    }
    *in = arr;
    scanf("%s",command);
    return size;


}


int GETHIGHT(AVLT *TREE){
    if(TREE == NULL){
        return 0;
    }else{
        return TREE->hight;
    }
}

int MAXV(AVLT *LEFT,AVLT *RIGHT){
    int right=GETHIGHT(RIGHT);
    int left=GETHIGHT(LEFT);
    return (left>right)?left:right;
}

int HIGHT_CAL(AVLT *TREE){
    return MAXV(TREE->LEFT,TREE->RIGHT)+1;
}

int BF_Cal(AVLT **TREE){
    return GETHIGHT((*TREE)->LEFT) - GETHIGHT((*TREE)->RIGHT);
}

void Right_Rotation(AVLT **TREE){
    AVLT *cpy = *TREE;
    AVLT *cpyl = (*TREE)->LEFT;
    if(cpyl->RIGHT!=NULL){
        cpy->LEFT = cpyl->RIGHT;
    }else{
        cpy->LEFT = NULL;
    }
    cpyl->RIGHT = cpy;
    (cpy)->hight=HIGHT_CAL(cpy);
    (cpyl)->hight=HIGHT_CAL(cpyl);
    *TREE = cpyl;

    return;
}

void Left_Rotation(AVLT **TREE){
    AVLT *cpy = *TREE;
    AVLT *cpyl = cpy->RIGHT;
    if(cpyl->LEFT!=NULL){
        cpy->RIGHT = cpyl->LEFT;
    }else{
        cpy->RIGHT = NULL;
    }
    cpyl->LEFT = cpy;
    (cpy)->hight=HIGHT_CAL(cpy);
    (cpyl)->hight=HIGHT_CAL(cpyl);
    *TREE = cpyl;

    return;
}

void Insert(AVLT **TREE, int val) {
    if (*TREE == NULL) {
        AVLT *new_node = (AVLT *)malloc(sizeof(AVLT));
        new_node->val = val;
        new_node->LEFT = NULL;
        new_node->RIGHT = NULL;
        new_node->hight = 1;
        *TREE = new_node;
    } else {
        if (val < (*TREE)->val) {
            Insert(&((*TREE)->LEFT), val);
        } else if (val > (*TREE)->val) {
            Insert(&((*TREE)->RIGHT), val);
        } else {
            return;
        }
    }


    (*TREE)->hight =     HIGHT_CAL(*TREE);

    if(BF_Cal(TREE)>100){
        exit(1);
    }
    if (BF_Cal(TREE) < -1) {
        if (BF_Cal(&((*TREE)->RIGHT)) > 0) {
            Right_Rotation(&((*TREE)->RIGHT));
        }
        Left_Rotation(TREE);
    } else if (BF_Cal(TREE) > 1) {
        if (BF_Cal(&((*TREE)->LEFT)) < 0) {
            Left_Rotation(&((*TREE)->LEFT));
        }
        Right_Rotation(TREE);
    }
}


void printtc(AVLT *TREE, int i){
    if(TREE == NULL){
        return;
    }

    printf("%d ",TREE->val,i);
    if(i>10000){
        exit(1);
    }
    printtc(TREE->LEFT,i+1);
    printtc(TREE->RIGHT,i+1);
}

void REinsert(AVLT **cpyti,AVLT **TREE){

    if(*cpyti == NULL){
        return;
    }
    Insert(TREE,(*cpyti)->val);
    REinsert(&((*cpyti)->LEFT),TREE);
    REinsert(&((*cpyti)->RIGHT),TREE);
}

int findminvalnode(AVLT **TREE){
    if((*TREE)->LEFT==NULL){
        return (*TREE)->val;
    }
    return findminvalnode(&((*TREE)->LEFT));
}

void Delete(AVLT **TREE,int val){
    if(*TREE == NULL){
        printf("Node not found.\n");
        return;
    }
    if((*TREE)->val==val){
        if((*TREE)->RIGHT == NULL && (*TREE)->LEFT == NULL){
            AVLT *cpy = NULL;
            *TREE = cpy;
            free(cpy);
        }else if((*TREE)->RIGHT == NULL){
            AVLT *Temp = (*TREE)->LEFT;
            AVLT *TRASH = *TREE;
            *TREE = Temp;
            free(TRASH);
        }else if((*TREE)->LEFT == NULL){
            AVLT *Temp = (*TREE)->RIGHT;
            AVLT *TRASH = *TREE;
            *TREE = Temp;
            free(TRASH);
        }
        else {
            int Temp = findminvalnode(&((*TREE)->RIGHT));
            (*TREE)->val=Temp;
            Delete(&((*TREE)->RIGHT),Temp);
        }

    }else if((*TREE)->val<val){
        Delete(&((*TREE)->RIGHT),val);
    }else if((*TREE)->val>val){
        Delete(&((*TREE)->LEFT),val);
    }

    if (*TREE != NULL) {
        (*TREE)->hight = HIGHT_CAL(*TREE);

        if (BF_Cal(TREE) > 1) {
            if (BF_Cal(&((*TREE)->LEFT)) < 0) {
                Left_Rotation(&((*TREE)->LEFT));
            }
            Right_Rotation(TREE);
        } else if (BF_Cal(TREE) < -1) {
            if (BF_Cal(&((*TREE)->RIGHT)) > 0) {
                Right_Rotation(&((*TREE)->RIGHT));
            }
            Left_Rotation(TREE);
        }
    }
    return;
}

void free_t(AVLT *TREE){
    if(TREE == NULL){
        return;
    }
    free_t(TREE->LEFT);
    free_t(TREE->RIGHT);
    free(TREE);
    return;
}

int main(){
    char command[10];
    int size,DV;
    int *insertarr = NULL;
    AVLT *TREE=(AVLT*)malloc(sizeof(AVLT));
    TREE = NULL;
    scanf("%s",command);
    while(strcmp(command,"EXIT")!=0){
        if(strcmp(command,"INSERT")==0){
            size = getinsert(&insertarr,command);
            for(int i =0;i<size;i++){
                Insert(&TREE,insertarr[i]);
            }
            free(insertarr);
        }else if(strcmp(command,"DELETE")==0){
            size = getinsert(&insertarr,command);
            for(int i =0;i<size;i++){
                Delete(&TREE,insertarr[i]);
            }
        }else if(strcmp(command,"PRINT")==0){
            if(TREE == NULL){
                printf("Tree is empty.\n");
            }else{
                printtc(TREE,0);
                printf("\n");
            }

            scanf("%s",command);
        }else{
            printf("Invalid command.\n");
            scanf("%s",command);
        }
    }
    free_t(TREE);
    return 0;
}
