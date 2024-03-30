//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *arr,int pos,int last) {
    int t = arr[pos];
    arr[pos] = arr[last];
    arr[last] = t;
}

void heapify(int *arr,int size,int t) {
    int left = 2*t+1,right = 2*t+2;
    if(t<0 || arr[t] == -999) return;
    if(arr[left]<arr[t] && arr[left]!=-999) {
        swap(arr,left,t);
    }
    else if(arr[right] < arr[t] && arr[right]!=-999) swap(arr,right,t);
    if(t%2==0) t=(t-2)/2;
    else t=(t-1)/2;
    heapify(arr,size,t);
}

void delete(int *arr,int val,int size) {
    int i=0;
    while(arr[i] != val) i++;
    swap(arr,i,size);
    arr[size] = -999;
}

int main() {
    char ch[10];
    int key,i=0,cnt=0,temp;
    int tree[1000];
    while(i!=1000) {
        tree[i]=-999;
        i++;
    }
    while (1) {
        scanf("%s", ch);
        if (strcmp(ch, "INSERT") == 0) {
            while (scanf("%d", &key) == 1) {
                tree[cnt] = key;
                if(cnt%2==0) temp=(cnt-2)/2;
                else temp=(cnt-1)/2;
                heapify(tree,cnt,temp);
                cnt++;
            }
        } else if (strcmp(ch, "DELETE") == 0) {
            while (scanf("%d", &key) == 1){
                cnt--;
                delete(tree,key,cnt);
                int pp = (cnt-1)/2;
                heapify(tree,cnt,pp);
                pp--;
                heapify(tree,cnt,pp);
            }
        } else if (strcmp(ch, "PRINT") == 0) {
            for(i=0;i<cnt;i++) {
                printf("%d ",tree[i]);
            }
            printf("\n");
        } else if (strcmp(ch, "EXIT") == 0) {
            break;
        }
    }
}
