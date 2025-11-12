#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	long long n = 0;
	scanf("%d",&n);
	long long *arr = NULL;
	long long *arr_backup = NULL;
	switch(n){
		case 1:
			printf("1\n");
			break;
		case 2:
			printf("1\n1 1\n");
			break;
		case 3:
			printf("1\n1 1\n1 2 1\n");
			break;
		case 4:
			printf("1\n1 1\n1 2 1\n1 3 3 1\n");
			break;
		default:
			arr = malloc(n*sizeof(long long));
			arr_backup = malloc(n*sizeof(long long));
			arr[0] = 1;
			arr[1] = 3;
			arr[2] = 3;
			arr[3] = 1;
			memcpy(arr_backup,arr,n*sizeof(long long));
			printf("1\n1 1\n1 2 1\n1 3 3 1\n");
			memcpy(arr_backup,arr,sizeof(arr));
			for(long long i=5;i<=n;i++){
				arr[0] = 1;
				for(long long r=1;r<=n-2;r++){
					arr[r] = arr_backup[r-1] + arr[r];
				}
				arr[n-1] = 1;
				for(long long t=0;t<=i-1;t++){
					printf("%lld",arr[t]);
					if(t == i-1){
						printf("\n");
					}else{
						printf(" ");
					}
				}
				memcpy(arr_backup,arr,n*sizeof(long long));
			}
			free(arr);
			free(arr_backup);
	}
}