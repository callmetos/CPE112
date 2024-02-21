//Channathat Ueanapaphon 66070503413
#include<stdio.h>
#include<stdlib.h>

int* insertArray(int* arr, int* size, int index, int value){
    if(index<0){
        printf("Index out of bounds\n");
        return arr;
    }else{
        *size+=1;
        int *newarr =(int *)malloc((*size)*sizeof(int));
        for(int i = 0;i<index;i++){
            *(newarr+i)=*(arr+i);
        }
        *(newarr+index)=value;
        for(int i = index+1;i<*size;i++){
            *(newarr+i)=*(arr+i-1);
        }
        free(arr);
        return newarr;
    }
}

int* deleteArray(int* arr, int* size, int index){
    if(index<0||index>=*size){
        printf("Index out of bounds\n");
        return arr;
    }else{
        *size-=1;
        int *newarr =(int *)malloc((*size)*sizeof(int));
        for(int i=0;i<index;i++){
            *(newarr+i)=*(arr+i);
        }
        for(int i = index;i<*size;i++){
            *(newarr+i)=*(arr+i+1);
        }
        free(arr);
        return newarr;
    }


}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}



int* mergeArray(int* arr1, int* size1, int* arr2, int size2){
    *size1+=size2;
    int *newarr =(int *)malloc((*size1)*sizeof(int));

    for(int i=0;i<*size1-size2;i++){
        *(newarr+i)=*(arr1+i);
    }
    for(int i=0;i<size2;i++){
        *(newarr+(*size1-size2)+i)=*(arr2+i);
    }
    free(arr1);
    return newarr;

}






int main(){


    int n,m,index,value;
    scanf("%d",&n,index);
    int* arr1=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",arr1+i);
    }
    scanf("%d",&m);
    int* arr2=(int *)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",arr2+i);
    }
    scanf("%d",&index);
    scanf("%d",&value);
    arr1 = realloc(arr1,(n+1)*sizeof(int));
    arr1 = insertArray(arr1,&n,index,value);
    if(index>=0){
        printArray(arr1,n);
    }


    scanf("%d",&index);
    if(index>=0&&index<n){
        arr1 = realloc(arr1,(n-1)*sizeof(int));
        arr1=deleteArray(arr1,&n,index);
        printArray(arr1,n);
    }else{
        arr1=deleteArray(arr1,&n,index);
    }

    arr1 = realloc(arr1,(n+m)*sizeof(int));
    arr1 = mergeArray(arr1,&n,arr2,m);

    printArray(arr1,n);

    free(arr1);
    free(arr2);
    return 0;
}
