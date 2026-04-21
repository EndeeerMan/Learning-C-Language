#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    if(*(int *)a > *(int *)b) return 1;
    else if(*(int *)a < *(int *)b) return -1;
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<=n-1;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);

    for(int i=0;i<=n-1;i++){
        printf("%d",arr[i]);
        if(i<n-1) printf(" ");
    }
}