#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int128(__int128 num){
	if(num == 0){
		printf("0");
		return;
	}
	if(num < 0){num = -num;putchar('-');}
	int arr[50];
	int digit = 0;
	int counter = 0;
	while(num > 0){
		digit = num % 10;
		num /= 10;
		arr[counter++] = digit;
	}
	for(int i=counter-1;i>=0;i--){
		printf("%d",arr[i]);
	}
	return;
}

int main(){
	long long n = 0;
	scanf("%lld",&n);
	__int128 *arr = NULL;
	__int128 *arr_backup = NULL;
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
			arr = malloc(n*sizeof(__int128));
			arr_backup = malloc(n*sizeof(__int128));
			arr[0] = 1;
			arr[1] = 3;
			arr[2] = 3;
			arr[3] = 1;
			memcpy(arr_backup,arr,n*sizeof(__int128));
			printf("1\n1 1\n1 2 1\n1 3 3 1\n");
			for(long long i=5;i<=n;i++){
				arr[0] = 1;
				for(long long r=1;r<=n-2;r++){
					arr[r] = arr_backup[r-1] + arr[r];
				}
				arr[n-1] = 1;
				for(long long t=0;t<=i-1;t++){
					print_int128(arr[t]);
					if(t == i-1){
						printf("\n");
					}else{
						printf(" ");
					}
				}
				memcpy(arr_backup,arr,n*sizeof(__int128));
			}
			free(arr);
			free(arr_backup);
	}
}