#include<stdio.h>

int main(){
	long long a;
	long long result;     //题目要求的数字很大，只有long long 整型数才能满足其要求而不使得数据溢出

	scanf("%lld",&a);

	if(a>1000000 || a < 0){
		printf("No Way!");
		return 1;
	}else{
		result = (a*(1+a))/2;
		printf("%lld",result);
	}

	return 0;
}