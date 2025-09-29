#include<stdio.h>

int main(){
	int a;
	int x,y,z;

	scanf("%d",&a);
	//百位数提取
	x = a;
	x = x - x%100;
	x = x / 100;
	//十位数提取
	y = a%100;
	y = y - y%10;
	y = y / 10;
	//个位数提取
	z = a%10;
	//判断三位数字输出哪些
	if(z==0&&y==0&&x==0){
		return 0;
	}else if(z==0&&y==0&&x!=0){
		printf("%d",x);
	}else if(z==0&&y!=0){
		printf("%d%d",y,x);
	}else if(z!=0){
		printf("%d%d%d",z,y,x);
	}else{
        printf("ERROR");
        return 1;
    }
	return 0;
}