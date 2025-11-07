#include <stdio.h>
#include <stdlib.h>

int main(){
    for(int num=1;num<=1000;num++){
        int *arr = NULL;
        int capacity = 1;
        int size = 0;
        arr = malloc(sizeof(int)*capacity);
        if(arr == NULL){
            printf("FATAL ERROR!\n");
            exit(1);
        }
        for(int i=1;i<num;i++){
            if(num%i == 0){
                if(capacity<=size){
                    capacity *= 2;
                    int *temp = realloc(arr,sizeof(int)*capacity);
                    if(temp == NULL){
                        printf("FATAL ERROR!\n");
                        free(arr);
                        exit(1);
                    }
                    arr = temp;
                }
                arr[size++] = i;
            }
        }
        int sum = 0;
        for(int i=0;i<size;i++){
            sum += arr[i];
        }
        if(sum == num){
            if(size == 0){
                printf("%d its factors are ",num);
            }else if(size == 1){
                printf("%d its factors are %d\n",num,arr[0]);
            }else if(size == 2){
                printf("%d its factors are %d,%d\n",num,arr[0],arr[1]);
            }else{
                printf("%d its factors are ",num);
                for(int i=0;i<=size-2;i++){
                    printf("%d,",arr[i]);
                }
                printf("%d\n",arr[size-1]);
            }
        }
        free(arr);
    }
    return 0;
}