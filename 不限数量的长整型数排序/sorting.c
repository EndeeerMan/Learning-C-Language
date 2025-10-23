#include <stdio.h>
#include <stdlib.h>

int main(){
    long long *arr = NULL;//Define a pointer with NULL.
    long long num = 0;//Pass the number into *arr.
    long size = 0; //Actually size that user has input.
    long capacity = 1; //Initial capacity of *arr.
    long long swapper = 0; //Bubble sorting numbers swapper.

    //Memory allocation initialization.

    arr = (long long *)malloc(capacity * sizeof(long long));

    if(arr == NULL){  //If allocate memory failed, the program exit with return value 1.
        printf("FATAL ERROR: Failed to allocate memory!\n");
        return 1;
    }else{
        printf("Successfully allocated memory! (8 Bytes)\nNow Please enter the integers that you want to sort, and end with Ctrl + D , then enter:\n");
    }
    //Detect user input.
    while(scanf("%lld",&num) == 1){
        if(capacity <= size){
            capacity *= 2; //If capacity not enough, extend memory with double capacity.
            arr = realloc(arr,capacity*sizeof(long long));
            if(arr == NULL){
                printf("FATAL ERROR: Failed to extend memory!\n");
                free(arr);
                return 1;
            }
        }
        arr[size++] = num;
    }
    
    printf("Detected numbers: ");
    for(int i=0;i<size;i++){
        printf("%lld ",arr[i]);
    }
    printf("\n\n");

    arrange:for(int i=0;i<size-1;i++){   //Bubble sorting.
                while(arr[i]>arr[i+1]){
                    swapper = arr[i];
                    arr [i] = arr[i+1];
                    arr[i+1] = swapper;
                }
            }

    for(int i=0;i<size-1;i++){ //Detect numbers sequence correct or not.
        if(arr[i]>arr[i+1]){
            goto arrange; //If not, sort again.
        }
    }

    for(int i=0;i<size;i++){
        printf("%lld\n",arr[i]);
    }

    free(arr); //Release memory resources.
    return 0;
}