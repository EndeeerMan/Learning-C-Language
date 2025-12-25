#include <stdio.h>
#include <stdlib.h>

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int should_swap(char *a,char *b){
    if(*a == *b) return 0;
    return 1;
}

void shuffle_and_print(char *arr,int l,int r){
    if(l == r){
        if(*arr == '0') return;
        printf("%s\n",arr);
        return;
    }
    for(int i=l;i<=r;i++){
        if(should_swap(&arr[l],&arr[i]) == 0) continue;
        swap(&arr[l],&arr[i]);
        shuffle_and_print(arr,l+1,r);
        if(should_swap(&arr[i],&arr[l])) continue;
        swap(&arr[i], &arr[l]);
    }
}

int main(){
    char *arr = NULL;
    int size = 0;
    int capacity = 1;
    arr = malloc(sizeof(char)*capacity);
    if(arr == NULL) exit(1);
    int temp;
    while(1){
        temp = getchar();
        if (temp == '\n' || temp == EOF) break;
        if(++size >= capacity) capacity *= 2;
        char *mem = realloc(arr,sizeof(char)*capacity);
        if(mem == NULL){
            exit(1);
            free(arr);
        }
        if(mem != NULL) arr = mem;
        arr[size-1] = temp;
    }
    char *mem = realloc(arr,sizeof(char)*(capacity+1));
    if(mem == NULL){
        exit(1);
        free(arr);
    }
    if(mem != NULL) arr = mem;
    arr[size] = '\0';
    shuffle_and_print(arr,0,size-1);
    free(arr);
}