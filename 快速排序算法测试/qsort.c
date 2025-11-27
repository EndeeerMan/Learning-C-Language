#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *arr,int left,int right){
    if(left >= right) return;
    int l = left;
    int r = right;
    int bench = arr[left];

    while(l < r){
        while(bench <= arr[r] && r > left){
            r--;
        }
        while(bench >= arr[l] && l < r){
            l++;
        }
        if(l != r) swap(&arr[l],&arr[r]);
    }
    
    swap(&arr[left],&arr[l]);
    quick_sort(arr,left,l-1);
    quick_sort(arr,l+1,right);
}

int main(){
    int *arr = NULL;
    int size = 0;
    int capacity = 1;
    arr = malloc(capacity * sizeof(int));
    if(arr == NULL) exit(1);
    
    int num = 0;
    while(scanf("%d",&num) != EOF){
        if(size >= capacity){
            capacity *= 2;
            int *temp = realloc(arr,capacity * sizeof(int));
            if(temp == NULL) exit(1);
            arr = temp;
        }
        arr[size++] = num;
    }
    if(size > 0) quick_sort(arr,0,size-1);

    for(int i=0;i<=size-1;i++){
        printf("%d",arr[i]);
        if(i<size-1) putchar(' ');
    }
    putchar('\n');

    free(arr);
}