#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long digits(long long num){
	if(num == 0) return 1;
	if(num < 0) num = -num;
	int counter = 0;
	while(num > 0){
		num /= 10;
		counter++;
	}
	return counter;
}

int main() {
	long long num = 0;
	scanf("%lld",&num);
	int *arr = NULL;
	int capacity = digits(num);
	arr = malloc(capacity * sizeof(long long));
	long long temp = num;
	for(int i=0;i<capacity;i++){
		arr[i] = temp / (long long)pow(10,(capacity-i-1));
		temp %= (long long)pow(10,(capacity-i-1));
	}
	for(int i=0;i<capacity;i++){
		printf("%d",arr[i]);
		if(i == capacity - 1){
			printf("\n");
			break;
		}else{
			printf(" ");
		}
	}
}