#include <stdio.h>
#include <stdlib.h>

int main(){
    long long *arr = NULL;
    long long num = 0;
    long size = 0;
    long capacity = 1;
    long long swapper = 0;
    //Memory allocation initialization.
    arr = (long long *)malloc(capacity * sizeof(long long));
    if(arr == NULL){
        printf("FATAL ERROR: Failed to allocate memory!\n");
        return 1;
    }else{
        printf("Successfully allocated memory! (8 Bytes)\nNow Please enter the integers that you want to sort, and end with EOF or any other chars + enter:\n");
    }
    while(scanf("%lld",&num) == 1){
        if(capacity <= size){
            capacity *= 2;
            arr = realloc(arr,capacity*sizeof(long long));
            if(arr == NULL){
                printf("FATAL ERROR: Failed to allocate memory!\n");
                free(arr);
                return 1;
            }
        }
        arr[size++] = num;
    }
    for(int i=0;i<size;i++){
        printf("%lld ",arr[i]);
    }
    printf("\n\n");
    arrange:for(int i=0;i<size-1;i++){
                while(arr[i]>arr[i+1]){
                    swapper = arr[i];
                    arr [i] = arr[i+1];
                    arr[i+1] = swapper;
                }
            }
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            goto arrange;
        }
    }
    for(int i=0;i<size;i++){
        printf("%lld\n",arr[i]);
    }
    free(arr);
    return 0;
}